# Test file for "lab3"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "PINA: 0x0f =>  PORTC: 0x3f - gas full"
setPINA 0x0f
continue 5
expectPORTC 0x3f
checkResult

test "PINA: 0x0d =>  PORTC: 0x3f - not full, but meter still says so"
setPINA 0x0d
continue 5
expectPORTC 0x3f
checkResult

test "PINA: 0x0b =>  PORTC: 0x3e - full - 1"
setPINA 0x0b
continue 5
expectPORTC 0x3e
checkResult

test "PINA: 0x08 =>  PORTC: 0x3c - full - 2"
setPINA 0x08
continue 5
expectPORTC 0x3c
checkResult

test "PINA: 0x05 =>  PORTC: 0x38 - full - 3"
setPINA 0x05
continue 5
expectPORTC 0x38
checkResult

test "PINA: 0x04 =>  PORTC: 0x70 - full - 4 with gas light"
setPINA 0x04
continue 5
expectPORTC 0x70
checkResult

test "PINA: 0x01 =>  PORTC: 0x60 - full - 5 with gas light"
setPINA 0x01
continue 5
expectPORTC 0x60
checkResult

test "PINA: 0x00 =>  PORTC: 0x40 - empty with gas light"
setPINA 0x00
continue 5
expectPORTC 0x40
checkResult

# Add tests below

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
