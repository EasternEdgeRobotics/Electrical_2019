__attribute__((section(".ramfunc"))) void delay_us(uint32_t n)
{
	__asm(
	"mydelay: \n"
	" mov  r1, #15    \n"  // 1 cycle
	"mydelay1: \n"
	" sub  r1, r1, #1 \n"  // 1 cycle
	" bne  mydelay1    \n" // 2 if taken, 1 otherwise
	" sub  r0, r0, #1 \n"  // 1 cycle
	" bne  mydelay    \n"  // 2 if taken, 1 otherwise
	);
}