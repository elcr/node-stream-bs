module Readable = {
    type t;

    [@bs.send.pipe: t]
    external on: ([@bs.string] [
        | `ready((unit => unit))
        | `error((Js.Exn.t => unit))
    ]) => unit = "on";
};


module Writeable = {
    type t;

    external toReadable: t => Readable.t = "%identity";
};
