/*
 * function: func_02175EFC
 * address: 0x02175EFC
 * packet: pkt_ov011_02175EFC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two alignment bytes at 02175F32 before F34.
 * interface: 08550's u8 getter is observed through a wide return and byte-base field conversion here, as the original truncation at 02175F22 proves.
 * lever: Direct assignment of the wide call result to the u8 bitfield interleaves its narrowing with the old-byte load; a u8 local gives 12 differing bytes.
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_021583EC 0x021583EC thumb ov010
 *   func_020084F8 0x020084F8 thumb
 *   func_02008550 0x02008550 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 pad[0x10]; u8 index; u8 flag:1; u8 rest:7; } Ent;
typedef struct Sub0200852CObj Sub0200852CObj;
extern u32 func_02026478(void *);
extern int func_021583EC(void *, int);
extern u32 func_020084F8(void *, u32, u32);
extern int func_02008550(const Sub0200852CObj *);
void func_02175EFC(void *w, Ent *p, u8 index)
{
    int rec;
    p->index = index;
    rec = func_021583EC((void *)func_02026478(((void **)w)[1]), p->index);
    func_020084F8((void *)rec, (u32)p, 8);
    p->flag = func_02008550((const Sub0200852CObj *)rec);
}
