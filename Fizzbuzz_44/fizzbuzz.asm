.data
rangeForInput: .asciiz "1st input is start, 2nd input is the end\n"	
newLine: .asciiz "\n"
fizz: .asciiz "Fizz"
buzz: .asciiz "Buzz"
space: .asciiz " "


.text
# Print output
li $v0, 4
la $a0, rangeForInput
syscall

# Read 1st int (start)
li $v0, 5
syscall
move $t0, $v0

# Read 2nd int (end)
li $v0, 5
syscall
move $t1, $v0

#$t0 = start; $t2 = end + 1
add $t2, $t1, 1
# Setting $k0 and $k1 to 3 and 5 respectively
li $k0, 3
li $k1, 5
# for(int i = start; i < end; i++)
startLoop:
	beq $t0, $t2, exitLoop
	div $t0, $k0	# TODO: make more efficient way to "divide"
	mfhi $s0
	beqz $s0, printFizz
	
afterThree:
	div $t0, $k1	# TODO: make more efficient way to "divide"
	mfhi $s1
	beq $s1, $zero, printBuzz
	# No need to check if divisible by 5 because when that happens, it jump to restartLoop
	beqz $s0, restartLoop
	# Prints number
	li $v0, 1 
	move $a0, $t0
	syscall
	j restartLoop
	
restartLoop:
	add $t0, $t0, 1
	li $v0, 4
	la $a0, space
	syscall
	j startLoop
	
printFizz:
	li $v0, 4
	la $a0, fizz
	syscall
	j afterThree

printBuzz:
	li $v0, 4
	la $a0, buzz
	syscall
	j restartLoop

exitLoop:
	# Closes program
	li $v0, 10
	syscall
