/*
 * function: func_021D8980
 * address: 0x021D8980
 * packet: pkt_ov119_021D8980
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH*
 * blocker: 021B65B4 (thumb, ov067 window) is an unlabelled function start:
 *  ov067 shows it as ARM data, bytes 00 22 82 60 52 1e 02 60 01 4b 01 22 18 47 c0 46
 *  (movs r2,#0; str r2,[r0,#8]; subs r2,#1; str r2,[r0]; ldr r3,pool; movs r2,#1; bx r3).
 *  Needs a layout start (figure move, not edited here). Parked 2026-10-02.
 * symbols:
 *   func_021B65B4 0x021B65B4 thumb ov067
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 */
extern void func_021B65B4(int,int);
extern void func_021B6558(int,int,int);
extern void func_021B6548(int,int,int);
void func_021D8980(char *p)
{
    func_021B65B4(*(int *)(p+0x9c0),1);
    func_021B6558(*(int *)(p+0x9c0),1,1);
    func_021B6548(*(int *)(p+0x9c0),1,1);
}
