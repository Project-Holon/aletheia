/*
 * function: func_0221268C
 * address: 0x0221268C
 * packet: pkt_ov199_0221268C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0221372C 0x0221372C thumb ov199
 *   func_022133D0 0x022133D0 thumb ov199
 *   func_0200B424 0x0200B424 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02012704 0x02012704 thumb
 *   func_02087BCC 0x02087BCC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02005D28 0x02005D28 thumb
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct S020315D4;
extern void func_0221372C(char *p);
extern void func_022133D0(char *);
extern void func_0200B424(void);
extern void func_020307B0(void *);
extern void func_02012704(u8 *p);
extern void func_02087BCC(u32 parameter);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32);
extern void func_02005D28(void);
int func_0221268C(void *sys, int unused, void *data, char *p)
{
    func_0221372C(*(void **)(p + 0x18));
    func_022133D0(p);
    func_0200B424();
    func_020307B0(*(void **)(p + 0x3c));
    func_020307B0(*(void **)(p + 0x38));
    func_020307B0(*(void **)(p + 0x34));
    func_020307B0(*(void **)(p + 0x30));
    if (*(int *)p) func_02012704(*(void **)(p + 4));
    if (*(int *)(p + 0xc) != 1) func_02087BCC(0);
    if (*(int *)(p + 0x14)) func_020307B0(data);
    func_020315D4(sys);
    func_020306F0(0x56);
    func_02005D28();
    return 1;
}
