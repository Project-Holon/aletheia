/*
 * function: func_021E55C8
 * address:  0x021E55C8
 * packet:   pkt_ov177_021E55C8
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021E8B5C     0x021E8B5C  data a4
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { u32 id; u32 template[8]; u32 type; u32 enable; } Entry;
extern const Entry d_021E8B5C[];
extern void func_020403F4(u8 id);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_02082BCC(void *p, u32 v, u32 n);

void func_021E55C8(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4(d_021E8B5C[i].id);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}
