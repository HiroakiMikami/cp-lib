import { Argument, Call, Create, Do, Identifier, Loop, Num, PolymorphicType, TypeArgument, TypeIdentifier } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./primitive.json", {
        typevarNames: new Map([
            ["Optional", ["V"]],
        ]),
        createArgNames: new Map([
            ["Integer", ["x"]],
            ["Float", ["x"]],
            ["String", ["x"]],
            ["Bool", ["x"]],
            ["Range", ["begin", "end", "step"]],
            ["Optional", []],
            ["Forever", []],
        ]),
        argNames: new Map([
            // operators
            ["op_add", ["lhs", "rhs"]],
            ["op_sub", ["lhs", "rhs"]],
            ["op_mul", ["lhs", "rhs"]],
            ["op_div", ["lhs", "rhs"]],
            ["op_eq", ["lhs", "rhs"]],
            ["op_ne", ["lhs", "rhs"]],
            ["op_gt", ["lhs", "rhs"]],
            ["op_ge", ["lhs", "rhs"]],
            ["op_lt", ["lhs", "rhs"]],
            ["op_le", ["lhs", "rhs"]],
            ["op_mod", ["lhs", "rhs"]],
            ["op_bitand", ["lhs", "rhs"]],
            ["op_bitor", ["lhs", "rhs"]],
            ["op_xor", ["lhs", "rhs"]],
            ["op_leftshift", ["lhs", "rhs"]],
            ["op_rightshift", ["lhs", "rhs"]],
            ["op_and", ["lhs", "rhs"]],
            ["op_or", ["lhs", "rhs"]],
            ["not", ["v"]],
            //cast
            ["float_to_integer", ["x"]],
            ["integer_to_float", ["x"]],
            ["integer_to_string", ["x"]],
            ["float_to_string", ["x", "precision"]],
            ["string_to_integer", ["x"]],
            ["string_to_float", ["x"]],
            // string
            ["size", ["container"]],
            ["add", ["container", "value"]],
            ["at", ["container", "key"]],
            ["update", ["container", "key", "value"]],
            ["remove", ["container", "key"]],
            ["reverse", ["container"]],
            // range
            ["For", ["b", "e"]],
            ["ReverseFor", ["b", "e"]],
            ["Rep", ["N"]],
            ["ReverseRep", ["N"]],
            // optional
            ["AsOptional", ["v"]],
            ["valid", ["v"]],
            ["from_optional", ["v"]],
        ]),
        dependencies: new Set(),
        snippets: [
            {
                name: "Base",
                color: "0",
                values: [
                    new Num("0", false),
                    new Num("1", false),
                    new Call(new Identifier("not"), [new Argument(new Identifier("x"), null)]),
                    new Call(new Identifier("float_to_integer"), [new Argument(new Identifier("x"), null)]),
                    new Call(new Identifier("integer_to_float"), [new Argument(new Identifier("x"), null)]),
                    new Call(new Identifier("integer_to_string"), [new Argument(new Identifier("x"), null)]),
                    new Call(
                        new Identifier("float_to_String"),
                        [
                            new Argument(new Identifier("x"), null),
                            new Argument(new Identifier("precision"), new Num("6", false)),
                        ]
                    ),
                    new Call(new Identifier("string_to_integer"), [new Argument(new Identifier("x"), null)]),
                    new Call(new Identifier("string_to_float"), [new Argument(new Identifier("x"), null)]),
                    new Create(
                        new PolymorphicType(
                            new TypeIdentifier("Optional"),
                            [new TypeArgument("V", null)],
                        ),
                        []
                    ),
                    new Call(new Identifier("AsOptional"), [new Argument(new Identifier("v"), null)]),
                    new Call(new Identifier("valid"), [new Argument(new Identifier("v"), null)]),
                    new Call(new Identifier("from_optional"), [new Argument(new Identifier("v"), null)]),
                ]
            },
            {
                name: "Loop",
                color: "0",
                values: [
                    new Loop(
                        new Identifier("_i"),
                        new Call(
                            new Identifier("For"),
                            [new Argument(new Identifier("b"), null),
                            new Argument(new Identifier("e"), null)]
                        ),
                        null
                    ),
                    new Loop(
                        new Identifier("_i"),
                        new Call(
                            new Identifier("ReverseFor"),
                            [new Argument(new Identifier("b"), null),
                            new Argument(new Identifier("e"), null)]
                        ),
                        null
                    ),
                    new Loop(
                        new Identifier("_i"),
                        new Call(
                            new Identifier("Rep"),
                            [new Argument(new Identifier("N"), null)],
                        ),
                        null
                    ),
                    new Loop(
                        new Identifier("_i"),
                        new Call(
                            new Identifier("ReverseRep"),
                            [new Argument(new Identifier("N"), null)],
                        ),
                        null
                    ),
                    new Loop(
                        new Identifier("_i"),
                        new Create(new TypeIdentifier("Forever"), []),
                        null
                    ),
                ]
            },
            {
                name: "String",
                color: "0",
                values: [
                    new Call(new Identifier("size"), [new Argument(new Identifier("container"), null)]),
                    new Do(
                        new Call(
                            new Identifier("add"),
                            [
                                new Argument(new Identifier("container"), null),
                                new Argument(new Identifier("value"), null),
                            ]
                        )
                    ),
                    new Call(
                        new Identifier("at"),
                        [
                            new Argument(new Identifier("container"), null),
                            new Argument(new Identifier("key"), null),
                        ]
                    ),
                    new Do(
                        new Call(
                            new Identifier("update"),
                            [
                                new Argument(new Identifier("container"), null),
                                new Argument(new Identifier("key"), null),
                                new Argument(new Identifier("value"), null),
                            ]
                        )
                    ),
                    new Do(
                        new Call(
                            new Identifier("remove"),
                            [
                                new Argument(new Identifier("container"), null),
                                new Argument(new Identifier("key"), null),
                            ]
                        )
                    ),
                    new Do(
                        new Call(
                            new Identifier("reverse"),
                            [new Argument(new Identifier("container"), null)]
                        )
                    ),
                ]
            },
        ]
    })
}
