/*
 * function: func_021D4940
 * address: 0x021D4940
 * packet: pkt_ov124_021D4940
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D49C6 before next labelled function.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 */
typedef short s16;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C724(void *,void *,s16,s16,void *,void *,u16);
void func_021D4940(char *p,int n)
{
    void *q;
    func_02043B5C(func_02045770(*(void **)(p + 0x24)),1);
    func_02043B5C(func_02045770(*(void **)(p + 0x20)),0);
    q = func_02045EC0(*(void **)(p + 0x2c),n);
    func_0201C724(*(void **)(p + 0x30),func_02045770(*(void **)(p + 0x24)),40,8,q,*(void **)(p + 0x28),0x3c40);
    func_02045808(q);
    n += 12;
    q = func_02045EC0(*(void **)(p + 0x2c),n);
    func_0201C724(*(void **)(p + 0x30),func_02045770(*(void **)(p + 0x20)),0,0,q,*(void **)(p + 0x28),0x3c40);
    func_02045808(q);
    *(int *)(p + 0x1c) = 1;
}
