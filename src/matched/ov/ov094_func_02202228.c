/*
 * function: func_02202228
 * address:  0x02202228
 * packet:   pkt_ov094_02202228
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INFOWIN_Update  0x02024ABC  thumb  arm9
 */
extern void *func_02030D28(void *);
extern void INFOWIN_Update(void *);

void func_02202228(void **p)
{
    INFOWIN_Update(func_02030D28(*p));
}
