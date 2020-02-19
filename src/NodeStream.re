module Readable = {
    type t;
};


module Writeable = {
    type t;

    external toReadable: t => Readable.t = "%identity";
};
