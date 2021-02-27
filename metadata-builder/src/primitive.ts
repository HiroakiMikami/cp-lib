import { Argument, Call, Identifier, Loop, Num } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./primitive.json", {
        typevarNames: new Map(),
        createArgNames: new Map([
            ["Integer", ["x"]],
            ["Float", ["x"]],
            ["String", ["x"]],
            ["Bool", ["x"]],
            ["Range", ["begin", "end", "step"]],
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
            //cast
            ["float_to_integer", ["x"]],
            ["integer_to_float", ["x"]],
            ["integer_to_string", ["x"]],
            ["float_to_string", ["x", "precision"]],
            ["string_to_integer", ["x"]],
            ["string_to_float", ["x"]],
            // range
            ["For", ["b", "e"]],
            ["ReverseFor", ["b", "e"]],
            ["Rep", ["N"]],
            ["ReverseRep", ["N"]],
        ]),
        dependencies: new Set(),
        snippets: [
            {
                name: "Base",
                color: "0",
                values: [
                    new Num("0", false),
                    new Num("1", false),
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
                ]
            }
        ]
    })
}
