/*
 * function: func_021DF648
 * address: 0x021DF648
 * packet: pkt_ov137_021DF648
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: 0x02010934 Thumb sole-ref/matched unavailable for interior unit member.
 * blocker: Verified EXACT with one in S30/blocker10934-r1.log:
 *   extern void func_020307B0(void *);
 *   void func_02010934(void *p) { func_020307B0(p); }
 *   symbols: func_020307B0 0x020307B0 arm
 * tail: 021DF6A2..021DF6A4 is two zero alignment bytes.
 * symbols:
 *   func_02010904 0x02010904 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   func_02010934 0x02010934 thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Sub0201088CObj;
extern u32 func_02010904(struct Sub0201088CObj *p);
extern unsigned func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern void WIPE_SetBrightnessFadeOut(unsigned, unsigned);
extern void TIME_ICON_Delete(u8 *p);
extern void func_02010934(struct Sub0201088CObj *p);
int func_021DF648(u8 *p)
{
    int ready;
    ready = func_02010904(*(void **)(p + 3488));
    if (func_0200FB24()) {
        func_0200FBB0();
        GFL_NET_ERR_ShowScreen(1);
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
        return 0;
    }
    if (ready) {
        TIME_ICON_Delete(*(void **)(p + 3496));
        *(void **)(p + 3496) = 0;
        func_02010934(*(void **)(p + 3488));
        *(int *)p = 47;
    }
    return 0;
}
