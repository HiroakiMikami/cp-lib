import { Call, Identifier, Argument } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./output.json", {
        typevarNames: new Map(),
        createArgNames: new Map(),
        argNames: new Map([
            ["sqrt", ["v"]],
            ["min", ["v0", "v1"]],
            ["max", ["v0", "v1"]],
        ]),
        dependencies: new Set(["primitive"]),
        snippets: [
            {
                name: "Math",
                color: "0",
                values: [
                    new Call(
                        new Identifier("sqrt"),
                        [new Argument(new Identifier("v"), null)]
                    ),
                    new Call(
                        new Identifier("min"),
                        [
                            new Argument(new Identifier("v0"), null),
                            new Argument(new Identifier("v1"), null),
                        ]
                    ),
                    new Call(
                        new Identifier("max"),
                        [
                            new Argument(new Identifier("v0"), null),
                            new Argument(new Identifier("v1"), null),
                        ]
                    ),
                ]
            },
        ]
    })

}