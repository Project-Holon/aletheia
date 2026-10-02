/*
 * function: func_021D4B44
 * address: 0x021D4B44
 * packet: pkt_ov123_021D4B44
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: callback 0x021D45F0 resolved by its verified ov123 shard.
 * symbols:
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D451C 0x021D451C thumb ov123
 *   func_021D45F0 0x021D45F0 thumb ov123
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 value; char *object; void (*callback)(char *); } Callback;
extern void func_0204B92C(void *, int);
extern void func_0204BA00(void *, Callback *);
extern void func_0204B9A0(void *);
extern void func_021D4244(char *, void *, int);
extern void func_021D451C(char *);
extern void func_021D45F0(void);
void func_021D4B44(char *p)
{
    Callback cb;
    cb.value = 0;
    cb.object = p;
    cb.callback = func_021D451C;
    func_0204B92C(*(void **)(p + *(u32 *)(p + 0x270) * 4 + 0x2a0), 1);
    func_0204BA00(*(void **)(p + *(u32 *)(p + 0x270) * 4 + 0x2a0), &cb);
    func_0204B9A0(*(void **)(p + *(u32 *)(p + 0x270) * 4 + 0x2a0));
    func_021D4244(p, func_021D45F0, 0x376);
}
