/*
 * file:     unit_021BBEA0.c
 * unit:     yes
 * function: func_021BBEA0, func_021BBEAC
 * address:  0x021BBEA0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned int u32_021BBEA0;

typedef unsigned long u32_021BBEAC;

void func_021BBEA0(u8 *p);
void NHTTPi_IsCreateCommThreadMessageQueueOff(void *threadInfo_p);

/*
 * Word setter at +0xec.
 */
void func_021BBEA0(u8 *p)
{
    *(u32_021BBEA0 *)(p + 0xec) = 1;
}


void NHTTPi_IsCreateCommThreadMessageQueueOff(void *threadInfo_p)
{
    *(u32_021BBEAC *)((char *)threadInfo_p + 0xEC) = 0;
}
