/*
 * function: func_021F42A8
 * address:  0x021F42A8
 * packet:   pkt_021F42A8
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb
 *   func_021897BC  0x021897BC  thumb
 *   func_02188C58  0x02188C58  thumb
 *   func_0218EC5C  0x0218EC5C  thumb
 *   func_0218EC54  0x0218EC54  thumb
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3038  0x021A3038  thumb
 *   func_021A3044  0x021A3044  thumb
 */
#include "../unit_021F36C0_types.h"

extern void *func_0201210C(void *gameSystem);
extern void *func_02188D2C(void *fieldMap);
extern void *func_021897BC(char *fieldMap, int id);
extern void *func_02188C58(void *fieldMap);
extern u32 func_0218EC5C(u8 *camera);
extern void func_0218EC54(u8 *camera);
extern VecFx32 *func_021BE480(void *expObj, unsigned unit, int model);
extern void *func_02188CB4(void *fieldMap);
extern void func_021A3038(unsigned char *player, VecFx32 *out);
extern void func_021A3044(u8 *player, VecFx32 *pos);

/* Puts the elevator at its upper end without the ride: the model and the
 * player are set to the top height and the camera is detached. */
void func_021F42A8(void *gameSystem)
{
    void *fieldMap;
    void *expObj;
    Gimmick43Work *work;
    u8 *camera;
    void *player;
    VecFx32 pos;

    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    camera = func_02188C58(fieldMap);
    work->savedCameraTarget = func_0218EC5C(camera);
    func_0218EC54(camera);
    func_021BE480(expObj, 0, 7)->y = 0x370000;
    player = func_02188CB4(fieldMap);
    func_021A3038(player, &pos);
    pos.y = 0x370000;
    func_021A3044(player, &pos);
}
