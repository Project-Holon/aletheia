/*
 * function: func_0221034C
 * address: 0x0221034C
 * packet: pkt_ov198_0221034C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * remainder: separate conditional follower ov198_func_0221039C.c (28 bytes).
 * symbols:
 *   func_02211958 0x02211958 thumb ov198
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_02211958(u8 **);
extern u32 func_020362DC(void);
extern u32 func_02035C60(void);
extern void func_0201F7A8(void *,u32);
int func_0221034C(char *p)
{
    if (func_02211958((u8 **)p)==1) return 0x1f;
    if ((func_020362DC()&3)!=0 || func_02035C60()==1) {
        if (*(u8 *)(p+0x2193)==1) {
            func_0201F7A8(*(void **)(p+0x1f68),0);
            *(u8 *)(p+0x2193)=0;
        }
        return *(int *)(p+0x217c);
    }
    return 0x18;
}
