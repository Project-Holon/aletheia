/*
 * function: GAME_COMM_Delete
 * address:  0x02026250
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 GFL_HEAP_Free(void *p);

struct Item {
    u32 unk0;
    void *vec1;
    void *vec2;
};

void GAME_COMM_Delete(void *obj)
{
    struct Item *items = (struct Item *)((u8 *)obj + 0x3c);
    int i;

    for (i = 0; i < 6; i++) {
        STRBUF_Delete(items[i].vec1);
        STRBUF_Delete(items[i].vec2);
    }
    GFL_HEAP_Free(obj);
}
