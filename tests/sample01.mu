/*
 * Hello World app in Mugen
 * Written By praisethemoon
 */
import (
    mugen.std.io,
    mugen.lang.String
)

enum ThreadState {
	INITIALIZING,
	RUNNING,
	PAUSING,
	STOPPED,
	DEAD
}

interface Runnable {
    function run()
}

interface StringObject{
    function toString() -> String
}

class HelloWorld implements Runnable, StringObject {
    let local message: String
    
    function new(msg: String) {
        self.message = msg
    }
    
    function printMessage() {
        Console.println(message)
    }
    
    function toString() -> String = String.format("HelloWorld[msg: %s]", msg)
}

function main(args: String[]) -> UInt32 {
    let app = new HelloWorld("hello, world!")
    app.printMessage()
    Console.println(app.toString())

    let mut t = [for i: Char in "hello, world" if isLowerCase(i) => i]
    
    return 0
}
