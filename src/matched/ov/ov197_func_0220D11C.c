/*
 * function: func_0220D11C
 * address: 0x0220D11C
 * packet: pkt_ov197_0220D11C
 * region: ov197
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: Ilias-owned ARM9 02045CAC has six unresolved calls; singleton TU confirms no viable cut.
 * Owner unit_02045C44.c omits func_02045CAC in function:. Verified EXACT344 C
 * below copied from ov173_func_021B71C4.c, prior ov070 fixed-flag --arm one.
 * abi: BBD8 returns a zero-extended u16; int extern preserves the original signed bge against the u8 field, unlike older unsigned caller externs.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * symbols:
 *   func_0220BBD8 0x0220BBD8 thumb ov197
 *   func_02045CAC 0x02045CAC arm
 *   func_0220B904 0x0220B904 thumb ov197
 *   func_02020FE4 0x02020FE4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0220BBD8(unsigned);
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0220B904(char *);
extern unsigned func_02020FE4(void *, unsigned, unsigned);
int func_0220D11C(char *p)
{
    char *q = *(char **)p;
    if (*(int *)(q + 8) == 1 && *(u8 *)(q + 0x14) < func_0220BBD8(*(u16 *)(q + 0x16))) {
        func_02045CAC(*(void **)(p + 0xc), 0x31, *(void **)(p + 0x14));
        func_0220B904(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    if (*(u8 *)(p + 0x533) == 2) {
        if (*(u8 *)(q + 0x28) == 1) {
            func_02045CAC(*(void **)(p + 0xc), 0x2d, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 2) {
            func_02045CAC(*(void **)(p + 0xc), 0x2c, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 3) {
            func_02045CAC(*(void **)(p + 0xc), 0x33, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
        if (*(u8 *)(q + 0x28) == 4) {
            func_02045CAC(*(void **)(p + 0xc), 0x2f, *(void **)(p + 0x14));
            func_0220B904(p);
            *(u8 *)(p + 0x531) = 0xd;
            return 0xe;
        }
    }
    if (*(u8 *)(q + 0x29) == 0 && func_02020FE4((void *)(unsigned)*(u16 *)(q + 0x16), 7, *(u16 *)(q + 0xc)) == 3) {
        func_02045CAC(*(void **)(p + 0xc), 0x32, *(void **)(p + 0x14));
        func_0220B904(p);
        *(u8 *)(p + 0x531) = 0xd;
        return 0xe;
    }
    return 0x12;
}
