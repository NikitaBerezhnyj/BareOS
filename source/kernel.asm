bits    32
section .text
    align 4
    dd 0x1BADB002
    dd 0x00
    dd - (0x1BADB002+0x00)
    
global start
extern main
global shutdown
global reboot

start:
    cli             ; Clear interrupts
    call main       ; Call the main function in C
    hlt             ; Halt the CPU

shutdown:
    cli             ; Clear interrupts
    ; Optional: Add code here to display a shutdown message (if you have a method to print from ASM)
    hlt             ; Halt the CPU indefinitely

reboot:
    cli             ; Clear interrupts
    mov al, 0xFE
    out 0x64, al    ; Send the reboot command to the keyboard controller
    hlt             ; Halt the CPU just in case
