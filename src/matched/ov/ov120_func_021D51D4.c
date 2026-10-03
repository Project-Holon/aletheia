/*
 * function: func_021D51D4
 * address: 0x021D51D4
 * packet: pkt_ov120_021D51D4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: The caller has no halfword truncation before func_021D79F4;
 * widen its copied u16 argument to int. Explicit calls in both branches
 * hoist the shared p+64 load; a ternary places it after the selection.
 * symbols:
 *   func_021D79F4 0x021D79F4 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D5188 0x021D5188 thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D79F4(u8 *,int); extern void func_021D4244(int,void (*)(int),int); extern void func_021D5188(int);
void func_021D51D4(u8 *p) { if (*(int *)(p+328)==-1) func_021D79F4(*(u8 **)(p+64),45); else func_021D79F4(*(u8 **)(p+64),31); func_021D4244((int)p,func_021D5188,0x646); }
