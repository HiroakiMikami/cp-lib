import * as fs from "fs"
import { Block } from "cp-dsl";
import { createJsonFromBlock } from "cp-dsl/out/src/syntax";

export interface Metadata {
    typevarNames: ReadonlyMap<string, ReadonlyArray<string>>
    createArgNames: ReadonlyMap<string, ReadonlyArray<string>>
    argNames: ReadonlyMap<string, ReadonlyArray<string>>
    dependencies: ReadonlySet<string>
    snippets: ReadonlyArray<{ name: string, color: string, values: ReadonlyArray<Block> }>
}


export function save(dst: string, metadata: Metadata) {
    let out: any = {
        typevarNames: {},
        createArgNames: {},
        argNames: {},
        dependencies: Array.from(metadata.dependencies),
        snippets: []
    }

    metadata.typevarNames.forEach((value, key) => out.typevarNames[key] = value)
    metadata.createArgNames.forEach((value, key) => out.createArgNames[key] = value)
    metadata.argNames.forEach((value, key) => out.argNames[key] = value)
    metadata.snippets.map(value => {
        out.snippets.push({
            name: value.name,
            color: value.color,
            values: value.values.map(createJsonFromBlock)
        })
    })

    fs.writeFileSync(dst, JSON.stringify(out, null, 2))
}
