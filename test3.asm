addi $t1, $zero, 1


beq $t0 ,$zero, IF1
beq $t0 , $t1, IF2
beq $t0, $t2, IF3
beq $t0, $t3, IF4
j DONE
IF1: sw $zero ($s0)
j DONE
IF2: mul $t1, $t1, 4
add $t1, $t1, $s0
sw $t2 , ($t1)
j DONE

IF3: mul $t1, $t1, 4
addi $t4 , $zero, 1
add $t1, $t1, $s0
sw $t4, ($t1)
j DONE

IF4:mul $t1, $t1, 4
addi $t4 , $zero, -1
add $t1, $t1, $s0 
sw $t4, ($t1)
j DONE

 DONE: 