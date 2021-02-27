import { Call, Identifier, Argument, Do } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./output.json", {
        typevarNames: new Map(),
        createArgNames: new Map(),
        argNames: new Map([
            ["set_precision", ["precision"]],
            ["print", ["v"]],
            ["dump", ["v"]],
        ]),
        dependencies: new Set(["primitive"]),
        snippets: [
            {
                name: "Output",
                color: "0",
                values: [
                    new Do(
                        new Call(
                            new Identifier("set_precision"),
                            [new Argument(new Identifier("precision"), null)]
                        ),
                    ),
                    new Do(
                        new Call(
                            new Identifier("print"),
                            [new Argument(new Identifier("v"), null)]
                        ),
                    ),
                    new Do(
                        new Call(
                            new Identifier("dump"),
                            [new Argument(new Identifier("v"), null)]
                        ),
                    ),
                ]
            },
        ]
    })
}
