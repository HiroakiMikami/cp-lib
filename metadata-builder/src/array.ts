import { Call, Identifier, Do, Argument } from "cp-dsl/out/src/syntax";
import { save } from "./_utils";

export function main(outdir: string) {
    save(outdir + "./array.json", {
        typevarNames: new Map([
            ["Array", ["V"]],
        ]),
        createArgNames: new Map(),
        argNames: new Map([
            ["size", ["container"]],
            ["add", ["container", "value"]],
            ["at", ["container", "key"]],
            ["update", ["container", "key", "value"]],
            ["remove", ["container", "key"]],
            ["reverse", ["container"]],
            ["sort", ["container", "cmp"]],
        ]),
        dependencies: new Set(["primitive"]),
        snippets: [
            {
                name: "Array",
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
                    new Do(
                        new Call(
                            new Identifier("sort"),
                            [
                                new Argument(new Identifier("container"), null),
                                new Argument(new Identifier("cmp"), null),
                            ],
                        )
                    ),
                ]
            },
        ]
    })
}
