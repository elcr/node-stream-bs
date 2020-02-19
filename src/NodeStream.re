type readable;
type writeable;


module Readable = {
    type t = readable;

    [@bs.send.pipe: t]
    external on: ([@bs.string] [
        | `ready((unit => unit))
        | `error((Js.Exn.t => unit))
    ]) => unit = "on";

    [@bs.send.pipe: t]
    external pipe: writeable => unit = "pipe";
};


module Writeable = {
    type t = writeable;

    [@bs.send.pipe: t]
    external on: ([@bs.string] [
        | `ready((unit => unit))
        | `error((Js.Exn.t => unit))
        | `close((unit => unit))
    ]) => unit = "on";

    external toReadable: t => readable = "%identity";
};
