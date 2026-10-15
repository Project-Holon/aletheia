/*
 * function: PSEL_GRAPHIC_Delete, PSEL_GRAPHIC_GetMaxState
 * unit: yes
 * trailing: parent-cleared Thumb follower 021BC348 is movs r0,#13; bx lr.
 * address: 0x021BC30C
 * packet: pkt_ov223_021BC30C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PSEL_UpdateB3AC 0x021BB3AC thumb ov223
 *   PSEL_DeleteWin 0x021BAEE0 thumb ov223
 *   PSEL_NopAB74 0x021BAB74 thumb ov223
 *   PSEL_DeleteG3dUtil 0x021B9848 thumb ov223
 *   PSEL_GRAPHIC_Destroy 0x021BC498 thumb ov223
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 */
extern int PSEL_UpdateB3AC(int *);
extern void PSEL_DeleteWin(char *p);
extern void PSEL_NopAB74(int *);
extern void PSEL_DeleteG3dUtil(int *);
extern void PSEL_GRAPHIC_Destroy(unsigned *);
struct Node;
extern void func_02030EAC(struct Node *n);
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
int PSEL_GRAPHIC_Delete(int *p)
{
    PSEL_UpdateB3AC(p); PSEL_DeleteWin((char *)p); PSEL_NopAB74(p); PSEL_DeleteG3dUtil(p);
    func_02030EAC((void *)p[8]); PRINTSYS_QUE_Clear((struct PrintSys *)p[7]); PRINTSYS_QUE_Delete((struct PrintSys *)p[7]);
    GF_FONT_Delete((void *)p[6]); PSEL_GRAPHIC_Destroy((unsigned *)p[5]);
    return 13;
}
int PSEL_GRAPHIC_GetMaxState(void) { return 13; }
