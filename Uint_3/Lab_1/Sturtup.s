@@ Eng.Elsayed Ayman Elsayed Ali Habib (Mastering Embedded System online Diploma)
.globl reset
reset: 
       ldr sp, =stack_top
       bl main
stop: b stop