mul $t0, $s1, $s2  

add $t0, $s0, $t0
addi $t2, $s1, 1
lw $s2, 0($t1)
sw $s2, 0($t0)



addi $t1, $zero, 1
addi $t2 , $zero, 2
addi $t3, $zero, 3
beq $t0 ,$zero, IF1
beq $t0 , $t1, IF2
beq $t0, $t2, IF3
beq $t0, $t3, IF4
j DONE
IF1: sw $zero 0($s0)
j DONE
IF2: mul $t1, $t1, 4
add $t1, $t1, $s0
sw $t2 , 0($t1)
j DONE

IF3: mul $t1, $t1, 4
addi $t4 , $zero, 1
add $t1, $t1, $s0
sw $t4, 0($t1)
j DONE

IF4:mul $t1, $t1, 4
addi $t4 , $zero, -1
add $t1, $t1, $s0 
sw $t4, 0($t1)
j DONE

 DONE: 