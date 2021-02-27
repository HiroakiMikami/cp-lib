import { Call, Identifier, Assign, Argument, Create, TypeIdentifier, PolymorphicType, TypeArgument } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./input.json", {
        typevarNames: new Map([
            ["Input", ["V"]],
            ["ArrayInput", ["V"]]
        ]),
        createArgNames: new Map([
            ["Input", []],
            ["ArrayInput", ["N"]]
        ]),
        argNames: new Map([
            ["read", ["x"]],
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
                        new Call(
                            new Identifier("read"),
                            [new Argument(
                                new Identifier("x"),
                                new Create(
                                    new PolymorphicType(
                                        new TypeIdentifier("Input"),
                                        [new TypeArgument("V", new TypeIdentifier("Integer"))]
                                    ),
                                    [],
                                )
                            )]
                        ),
                    ),
                    new Assign(
                        new Identifier("_f"),
                        true,
                        new Call(
                            new Identifier("read"),
                            [new Argument(
                                new Identifier("x"),
                                new Create(
                                    new PolymorphicType(
                                        new TypeIdentifier("Input"),
                                        [new TypeArgument("V", new TypeIdentifier("Float"))]
                                    ),
                                    [],
                                )
                            )]
                        ),
                    ),
                    new Assign(
                        new Identifier("_str"),
                        true,
                        new Call(
                            new Identifier("read"),
                            [new Argument(
                                new Identifier("x"),
                                new Create(
                                    new PolymorphicType(
                                        new TypeIdentifier("Input"),
                                        [new TypeArgument("V", new TypeIdentifier("String"))]
                                    ),
                                    [],
                                )
                            )]
                        ),
                    ),
                    new Assign(
                        new Identifier("_xs"),
                        true,
                        new Call(
                            new Identifier("read"),
                            [new Argument(
                                new Identifier("x"),
                                new Create(
                                    new PolymorphicType(
                                        new TypeIdentifier("ArrayInput"),
                                        [new TypeArgument("V", new TypeIdentifier("Integer"))]
                                    ),
                                    [new Argument(new Identifier("N"), null)],
                                )
                            )]
                        ),
                    ),
                    new Assign(
                        new Identifier("_fs"),
                        true,
                        new Call(
                            new Identifier("read"),
                            [new Argument(
                                new Identifier("x"),
                                new Create(
                                    new PolymorphicType(
                                        new TypeIdentifier("ArrayInput"),
                                        [new TypeArgument("V", new TypeIdentifier("Float"))]
                                    ),
                                    [new Argument(new Identifier("N"), null)],
                                )
                            )]
                        ),
                    ),
                    new Assign(
                        new Identifier("_ss"),
                        true,
                        new Call(
                            new Identifier("read"),
                            [new Argument(
                                new Identifier("x"),
                                new Create(
                                    new PolymorphicType(
                                        new TypeIdentifier("ArrayInput"),
                                        [new TypeArgument("V", new TypeIdentifier("String"))]
                                    ),
                                    [new Argument(new Identifier("N"), null)],
                                )
                            )]
                        ),
                    ),
                ]
            },
        ]
    })
}
