/*
 * function: NAMEIN_GRAPHIC_CallbackWaitDraw
 * address: 0x021F463C
 * packet: pkt_ov194_021F463C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_IsGridDrawDone 0x021F3304 thumb ov194
 *   NAMEIN_GRAPHIC_IsFieldDrawDone 0x021F22E8 thumb ov194
 *   NAMEIN_GRAPHIC_IsMsgDrawDone 0x021F3E78 thumb ov194
 *   NAMEIN_GRAPHIC_SetCallback 0x021F462C thumb ov194
 *   NAMEIN_GRAPHIC_CallbackFadeIn 0x021F4674 thumb ov194
 */
extern int NAMEIN_GRAPHIC_IsGridDrawDone(char *),NAMEIN_GRAPHIC_IsFieldDrawDone(unsigned char *),NAMEIN_GRAPHIC_IsMsgDrawDone(unsigned char *);
extern void NAMEIN_GRAPHIC_SetCallback(unsigned char *,unsigned),NAMEIN_GRAPHIC_CallbackFadeIn(unsigned char *,int *);
void NAMEIN_GRAPHIC_CallbackWaitDraw(unsigned char *p,int *unused,unsigned char *q){int v;v=NAMEIN_GRAPHIC_IsGridDrawDone((char *)(q+252));v|=NAMEIN_GRAPHIC_IsFieldDrawDone(q+104);if(NAMEIN_GRAPHIC_IsMsgDrawDone(q+560)|v)NAMEIN_GRAPHIC_SetCallback(p,(unsigned)NAMEIN_GRAPHIC_CallbackFadeIn);}
