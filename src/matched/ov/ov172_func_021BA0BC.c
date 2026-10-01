/*
 * unit: yes
 * function: func_021BA0BC, func_021BA114
 * address: 0x021BA0BC
 * packet: pkt_ov172_021BA0BC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082A7C 0x02082A7C arm
 *   func_0208B500 0x0208B500 arm
 * extent: Callback at 021BA114 stores zero at r1+8 and 51200 at r1.
 */
typedef unsigned int u32;
typedef enum MICResult { MIC_SUCCESS, MIC_BUSY, MIC_ILLEGAL, MIC_SEND_ERROR } MICResult;
typedef struct MICAutoParam {
    int type;
    void *buffer;
    u32 size;
    u32 rate;
    int loop;
    void (*callback)(MICResult, void *);
    void *arg;
} MICAutoParam;
extern void func_02082A7C(u32, void *, u32);
extern MICResult func_0208B500(MICAutoParam *);
void func_021BA114(MICResult, void *);
int func_021BA0BC(u32 *p)
{
    MICAutoParam param;
    param.type = 3;
    param.size = 51200;
    param.buffer = (void *)p[1];
    func_02082A7C(0, param.buffer, param.size);
    if (param.size & 31) param.size &= ~31;
    param.callback = func_021BA114;
    param.loop = 0;
    param.rate = 4097;
    param.arg = p;
    if (func_0208B500(&param) == 0) {
        p[2] = 1;
        p[0] = 0;
        return 1;
    }
    return 0;
}
void func_021BA114(MICResult result, void *arg)
{
    u32 *p = arg;
    p[2] = 0;
    p[0] = 51200;
}
