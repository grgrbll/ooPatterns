


Both the adaptor and facade are used to change the interface of an existing object to
fit a new format.

When using the adaptor, that new format disguises the object as another type of object
and allows it to be used interchangably. For example, allowing data to be written to a
socket or harddrive opaquely to the calling code.

A facade on the other hand does not care about fitting the object to a shared inferface,
instead we just want to make the usage of an object simpler, similar to how most scripting 
languages simplify the socket interface.
