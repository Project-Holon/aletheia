/*
 * function: func_021B6B38
 * address: 0x021B6B38
 * packet: pkt_ov071_021B6B38
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 */
struct Obj;
struct Grid;
struct Obj020437AC;
extern void CLACT_DeleteActor(struct Obj *);
extern void BMP_OAM_Delete(struct Grid *);
extern void BMP_Delete(struct Obj020437AC *);
void func_021B6B38(void **p)
{
    CLACT_DeleteActor(p[0]);
    BMP_OAM_Delete(p[1]);
    BMP_Delete(p[2]);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}
