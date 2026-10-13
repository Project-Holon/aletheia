/*
 * function: func_02210E20
 * address: 0x02210E20
 * packet: pkt_ov198_02210E20
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever (wave 82 R8): the switch has no default arm. The image's `bhi`
 *   for a selector above 6 goes straight to the shared tail with `text`
 *   (r7) never assigned, exactly what the C says (see
 *   docs/idioms/switch-arms-tail-merge.md); matched func_02210DA8 returns
 *   only 0..6, so that path is never taken. A `case 0: default: return 1;`
 *   arm is DIFF54. The `adds r5,r4,#4` above the multiply needs the index
 *   multiplied in its own statement after base (`index*=76;`); `76*f()`
 *   and `f()*76` initialisers are DIFF4.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210DA8 0x02210DA8 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_022110D4(u8 *,int);
extern int func_02210DA8(u8 *);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
int func_02210E20(u8 *p)
{
    u32 index=func_022110D4(p,(*(u8 **)p)[32]);
    u8 *base=p+4;
    void *text;
    index*=76;
    switch((u32)func_02210DA8(p)) {
    case 1: text=func_02045EC0(*(void **)(p+0x1EA0),90); break;
    case 2:
        text=func_02045EC0(*(void **)(p+0x1EA0),87);
        func_0201EEF4(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 3:
        text=func_02045EC0(*(void **)(p+0x1EA0),86);
        func_0201EEF4(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 4:
        text=func_02045EC0(*(void **)(p+0x1EA0),103);
        func_0201EEF4(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 5: text=func_02045EC0(*(void **)(p+0x1EA0),89); break;
    case 6:
        index=76*(*(u8 **)p)[33];
        text=func_02045EC0(*(void **)(p+0x1EA0),88);
        func_0201EEF4(*(void **)(p+0x1EA4),0,*(void **)(base+index));
        break;
    case 0: return 1;
    }
    func_0201F250(*(void **)(p+0x1EA4),*(void **)(p+0x1EA8),text);
    STRBUF_Delete(text);
    return 0;
}
