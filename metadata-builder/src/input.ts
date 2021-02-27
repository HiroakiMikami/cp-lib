import { Call, Identifier, Assign } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./input.json", {
        typevarNames: new Map(),
        createArgNames: new Map(),
        argNames: new Map([
            ["read_integer", []],
            ["read_float", []],
            ["read_string", []],
        ]),
        dependencies: new Set(["primitive"]),
        snippets: [
            {
                name: "Input",
                color: "0",
                values: [
                    new Assign(
                        new Identifier("_N"),
                        true,
                        new Call(new Identifier("read_integer"), []),
                    ),
                    new Assign(
                        new Identifier("_f"),
                        true,
                        new Call(new Identifier("read_float"), []),
                    ),
                    new Assign(
                        new Identifier("_str"),
                        true,
                        new Call(new Identifier("read_string"), []),
                    ),
                ]
            },
        ]
    })
}
