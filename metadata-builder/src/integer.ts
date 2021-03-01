import { Call, Identifier, Argument } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./integer.json", {
        typevarNames: new Map(),
        createArgNames: new Map(),
        argNames: new Map([
            ["integer_as_digit", ["x"]],
            ["integer_to_lower_order", ["x"]],
            ["integer_to_upper_order", ["x"]],
        ]),
        dependencies: new Set(["primitive"]),
        snippets: [
            {
                name: "Integer",
                color: "0",
                values: [
                    new Call(
                        new Identifier("integer_as_digit"),
                        [new Argument(new Identifier("x"), null)]
                    ),
                    new Call(
                        new Identifier("integer_to_lower_order"),
                        [new Argument(new Identifier("x"), null)]
                    ),
                    new Call(
                        new Identifier("integer_to_upper_order"),
                        [new Argument(new Identifier("x"), null)]
                    ),
                ]
            },
        ]
    })
}
