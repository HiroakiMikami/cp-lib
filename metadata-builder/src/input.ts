import { Call, Identifier, Assign, Argument } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./input.json", {
        typevarNames: new Map(),
        createArgNames: new Map(),
        argNames: new Map([
            ["read_integer", []],
            ["read_float", []],
            ["read_string", []],
            ["read_integer_array", ["N"]],
            ["read_float_array", ["N"]],
            ["read_string_array", ["N"]],
        ]),
        dependencies: new Set(["primitive", "array"]),
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
                    new Assign(
                        new Identifier("_xs"),
                        true,
                        new Call(
                            new Identifier("read_integer_array"),
                            [new Argument(new Identifier("N"), null)],
                        ),
                    ),
                    new Assign(
                        new Identifier("_xs"),
                        true,
                        new Call(
                            new Identifier("read_float_array"),
                            [new Argument(new Identifier("N"), null)],
                        ),
                    ),
                    new Assign(
                        new Identifier("_xs"),
                        true,
                        new Call(
                            new Identifier("read_string_array"),
                            [new Argument(new Identifier("N"), null)],
                        ),
                    ),
                ]
            },
        ]
    })
}
