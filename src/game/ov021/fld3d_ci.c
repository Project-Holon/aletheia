/*
 * file:     fld3d_ci.c
 * unit:     yes
 * function: func_021C1988, func_021C19B4, func_021C1A08, func_021C1A48, func_021C1A84, func_021C1A98, func_021C1AA8, func_021C1AB4, func_021C1AD0, func_021C1AEC, func_021C1AF4, func_021C1C04, func_021C1C24, func_021C1C4C, func_021C1CB0, func_021C1D18, func_021C1D68, func_021C1DCC, func_021C1E7C, func_021C21B4, func_021C223C, func_021C22AC, func_021C2320, func_021C2484, func_021C24A8, func_021C24BC, func_021C24F0, func_021C2734, func_021C2764, func_021C2784, func_021C27A4, func_021C27C0, func_021C27CC, func_021C27E8, func_021C27F4, func_021C2854, func_021C2918, func_021C2B1C, func_021C2B5C, func_021C2B98, func_021C2BD4, func_021C2BE4, func_021C2CF4, func_021C2D68, func_021C2EBC, func_021C2ECC, func_021C2EDC, func_021C2F14, func_021C2F50, func_021C2F84, func_021C30B8, func_021C30D4, func_021C313C, func_021C3158, func_021C3198
 * address:  0x021C1988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C16AC  0x021C16AC  thumb  ov021
 *   d_021DA128     0x021DA128  data  ov021
 *   func_021A572C  0x021A572C  thumb  ov021
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_02050B80  0x02050B80  arm
 *   d_021DE3C8     0x021DE3C8  data  ov021  a4
 *   func_02050DB8  0x02050DB8  arm
 *   func_02051230  0x02051230  arm
 *   func_02050ED4  0x02050ED4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02050BE8  0x02050BE8  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02048A24  0x02048A24  arm
 *   d_021DE3D8     0x021DE3D8  data  a4
 *   d_021DA6E8     0x021DA6E8  data  a4
 *   d_021DA6D0     0x021DA6D0  data  a4
 *   d_021DA6F4     0x021DA6F4  data  a4
 *   d_021DA6DC     0x021DA6DC  data  a4
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   func_02047E88  0x02047E88  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047A60  0x02047A60  arm
 *   func_0203038C  0x0203038C  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DA7F4     0x021DA7F4  data  ov021  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017EAC  0x02017EAC  thumb
 *   abs_id_4A      0x0000004A  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F54E0  0x021F54E0  thumb  ov075
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02189A58  0x02189A58  thumb  ov021
 *   func_0204047C  0x0204047C  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   func_02188C64  0x02188C64  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 *   func_02030830  0x02030830  arm
 *   func_021899F8  0x021899F8  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_0207DD24  0x0207DD24  arm
 *   func_02188C60  0x02188C60  thumb  ov021
 *   func_021A0568  0x021A0568  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_02193068  0x02193068  thumb  ov021
 *   func_021BC5D4  0x021BC5D4  thumb  ov021
 *   func_021904D0  0x021904D0  thumb  ov021
 *   func_020414AC  0x020414AC  arm
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   d_021DA710     0x021DA710  data  ov021  a4
 *   func_0204779C  0x0204779C  arm
 *   func_020478B8  0x020478B8  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02051B04  0x02051B04  arm
 *   func_020480E4  0x020480E4  arm
 *   func_020515CC  0x020515CC  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_02043658  0x02043658  arm
 *   func_02043534  0x02043534  arm
 *   func_020124F0  0x020124F0  thumb
 *   func_020437AC  0x020437AC  arm
 *   func_02006CAC  0x02006CAC  thumb
 *   func_02006984  0x02006984  thumb
 *   func_02006650  0x02006650  thumb
 *   func_02006B20  0x02006B20  thumb
 *   func_02006A8C  0x02006A8C  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_02043678  0x02043678  arm
 *   func_02048A0C  0x02048A0C  arm
 *   func_02047388  0x02047388  arm
 *   func_020473B8  0x020473B8  arm
 *   func_0202D060  0x0202D060  thumb
 *   func_0202D064  0x0202D064  thumb
 *   func_0202D0D4  0x0202D0D4  thumb
 *   func_02049E34  0x02049E34  arm
 *   func_02049F34  0x02049F34  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02082A90  0x02082A90  arm
 *   func_02044F64  0x02044F64  arm
 *   func_02061CA4  0x02061CA4  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_02046F48  0x02046F48  arm
 *   func_0206E964  0x0206E964  arm
 *   func_02049DB4  0x02049DB4  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02046BE0  0x02046BE0  arm
 *   d_021DE3E4     0x021DE3E4  data  ov021  a4
 *   d_021DE3F4     0x021DE3F4  data  ov021  a4
 *   d_021DE404     0x021DE404  data  ov021  a4
 *   d_021DE40C     0x021DE40C  data  ov021  a4
 *   d_021DE418     0x021DE418  data  ov021  a4
 *   d_021DE428     0x021DE428  data  ov021  a4
 *   d_021DE43C     0x021DE43C  data  ov021  a4
 *   d_021DE448     0x021DE448  data  ov021  a4
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201F4A0  0x0201F4A0  thumb
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0216FAB4  0x0216FAB4  thumb  ov010
 *   func_02045C04  0x02045C04  arm
 *   d_021DA720     0x021DA720  data  ov021
 *   d_021DA700     0x021DA700  data  ov021
 */
#include "fld3d_ci_types.h"

typedef signed char s8;
typedef signed short s16;
typedef volatile unsigned short vu16;
typedef struct Bmp Bmp;
typedef int (*Fld3dCiStateFunc)(u16 *state);
struct Bmp;

extern void func_021C16AC(u8 *p);
extern void *func_021A572C(u8 *p);
extern void *func_0216D67C(void *a0);
extern int func_0216D83C(void *p);
extern int func_021641E8(int a);
extern int func_0216D86C(void *p);
extern int func_021641F8(int a);
extern u32 func_0216D8AC(void *p);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02050B80(u32);
extern void *func_02050C04(int a, int b, int c, int d);
extern void *func_02051788(void *effect);
extern void func_02048B60(void *effect, const u32 *in);
extern void func_02048B6C(void *effect, const u32 *in);
extern void func_02050DB8(void *effect);
extern int func_0205121C(u32 a, u32 b, u32 c);
extern u32 func_02051230(u32, u32, u32, u32);
extern int func_02051614(int **p);
extern u32 func_020307B0(void *p);
extern void func_02050ED4(void);
extern void func_02050BE8();
extern void *func_02047CFC(int a, int b, int heap);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h, VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern u32 func_02048AC4(void *camera);
extern void func_02047E54(void *gfxUnits);
extern u32 func_02047E88(u32, u32);
extern u32 func_0207ADC4(u32);
void func_02048AD0(void *camera);
u32 func_020489F4(void *gfxUnits, int index);
u32 func_02048A00(void *gfxUnits, int index);
u32 func_02048A18(void *gfxUnits, int index);
void func_02047A60(void *object, G3dObjectStatus *status);
u32 func_0203038C(int a);
extern void *func_020122C0(void *gameSystem, void *parent, void *func, u32 workSize);
extern void *func_020124E8(void *event);
void *func_020120F4(const void *p);
void *func_02012934(const void *p);
extern void *func_0201AB28(void *p, u32 idx);
u32 func_02017E1C(void *p, u32 id, u32 v);
u32 func_02017EAC(void *p);
int func_02034AC4(signed int id);
void func_02034A5C(int id);
int *func_021F54E0(int a);
extern void *func_020124E4(void *event);
extern void *func_0201210C(const void *p);
extern void *func_02188C7C(unsigned char *p);
extern void func_0216D9A0(void *o);
extern void func_02012374(void *event, void *child);
extern void *func_02188CB4(void *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216CF2C(u32 a);
extern void func_02189A58(u8 *p, u32 v);
extern void func_0204047C(int idx, unsigned short val);
extern void func_0203FC28(void *dispConfig);
extern void func_0207FDCC(int a);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u32 func_02188C64(u8 *p);
extern int func_021A01A4(u32 a, u32 b);
extern void *func_02030830(u32 heapId);
extern void func_021899F8(u8 *p, u32 v);
extern int func_02005C64(void);
extern void func_0216D5E0(int a0, int a1);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern u32 func_02188C60(u8 *p);
extern void func_021A0568(u8 *p, int force);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern u32 func_02188C54(u8 *p);
extern u32 func_02188D20(u8 *p);
extern void func_02193068(char *p);
extern void func_021BC5D4(u8 *p);
extern void func_021904D0(u8 *p);
extern void func_020414AC(int);
extern u32 *func_0216D9E4(void *c);
int func_0204779C(G3dObject *object);
int func_020478B8(G3dObject *object, int animIndex, int amount);
u32 func_020477A4(G3dObject *object, u32 animIndex);
u16 func_02051B04(void *res);
extern void func_020480E4(void *gfxUnits, u32 index);
int func_020515CC(int *p, int a, int b, int c);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0208068C(u32 a);
extern void func_02030EAC(void *n);
extern u8 func_020416D4(u32 layer);
u32 func_02043658(void);
extern void func_02043534(u32 a);
extern void *func_020124F0(void *event);
void func_020437AC(void *bmp);
void func_02006CAC(void **out);
unsigned int func_02006984(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7);
int func_02006650(void);
s8 func_02006B20(u32 i);
void func_02006A8C(u32 idx, int delta);
void func_020065D8(void);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_02048A0C(void *gfxUnits, int index);
extern u32 func_02047388(void *texBlock);
extern u32 func_020473B8(void *texBlock);
extern int func_0202D060(void);
extern s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern s32 func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern struct Bmp *func_02044F64(struct Bmp *src, u32 keep, u16 heap);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
extern void *func_02046F48(void *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02012944(void *gameData);
extern u8 func_02008550(const void *playerStatus);
extern void func_02046BE0(u32 a, u32 b);
extern int func_0206E62C(void *dict, Fld3dCiNameKey *key);
extern int func_0208CC78(const char *s);
extern void *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201EC64(u32 heap);
extern void *func_020457B0(u32 size, u16 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201F02C(void *wordSet, u32 index, void *playerStatus);
extern void func_0201F250(void *ws, void *dst, void *src);
extern void func_02045808(void *vec);
extern u32 func_0201ED04(void *p);
extern void func_0201F4A0(void *dst, void *src);
extern void *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D304(void *s, u32 a, u32 b);
extern u32 func_0201D83C(void *ptr);
extern int func_0216FAB4(void *texBlock, const char *texName, void *palette, const char *plttName, u32 text, u16 xOffset, u16 a6, u16 a7, u16 heap, void *texKey);
extern u32 func_02045C04(void *rec);
extern int func_020808F4(void);
extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_020061E4(u32 a);
void func_021C1988(void *work, u16 *state);
u32 func_021C19B4(u8 *work, u32 direction);
FldParticle *func_021C1A08(u32 heapId);
void *func_021C1A48(FldParticle *particle);
void func_021C1A84(FldParticle *particle);
void *func_021C1A98(FldParticle *particle, int kind, int resourceId);
int func_021C1AA8(FldParticle *particle, u32 resource, u32 arg0, u32 arg1);
int func_021C1AB4(FldParticle *particle);
u32 func_021C1AD0(FldParticle *particle);
void func_021C1AEC(void);
Fld3dCi *func_021C1AF4(u32 heapId, FldParticle *particle);
void func_021C1C04(Fld3dCi *ci);
int func_021C1C24(Fld3dCi *ci, Fld3dCiResource **resourceTable);
void func_021C1C4C(Fld3dCi *ci);
void *func_021C1CB0(void *gameSystem, Fld3dCi *ci, int sequenceId);
void *func_021C1D18(void *gameSystem, Fld3dCi *ci, int species, int form, int attr6E, int personality, int attr4C);
void *func_021C1D68(void *gameSystem, Fld3dCi *ci, int partyPos);
void *func_021C1DCC(void *gameSystem, Fld3dCi *ci, int tableIndex, int fadeVariant);
int func_021C1E7C(void *event, int *state, Fld3dCiEventWork *work);
int func_021C21B4(Fld3dCi *ci);
int func_021C223C(Fld3dCi *ci);
int func_021C22AC(Fld3dCi *ci);
void func_021C2320(void *event, Fld3dCi *ci, Fld3dCiSeq *seq, int sequenceId);
void func_021C2484(Fld3dCi *ci, Fld3dCiSeq *seq);
void func_021C24A8(Fld3dCi *ci, int track);
void func_021C24BC(Fld3dCiFollow *follow);
void func_021C24F0(Fld3dCiSeq *seq, u32 sequenceId, u32 heapId);
void func_021C2734(Fld3dCiSeq *seq);
void func_021C2764(Fld3dCi *ci);
void func_021C2784(void *task, u32 *done);
void func_021C27A4(Fld3dCi *ci);
void func_021C27C0(Fld3dCi *ci);
void func_021C27CC(Fld3dCi *ci);
void func_021C27E8(Fld3dCi *ci);
int func_021C27F4(void *event, int *state);
int func_021C2854(void *event, Fld3dCi *ci);
void func_021C2918(Fld3dCi *ci);
int func_021C2B1C(void *event, int *state);
int func_021C2B5C(void *event, int *state);
int func_021C2B98(void *event, u32 *state);
int func_021C2BD4(u16 sequenceId);
void func_021C2BE4(Fld3dCi *ci, const char *texName, const char *plttName, u32 chrFile, u32 plttFile);
int func_021C2CF4(void *event, Fld3dCi *ci);
int func_021C2D68(void *event, int *state);
int func_021C2EBC(Fld3dCiTexBlock *texBlock, Fld3dCiTexDictEntry *entry);
int func_021C2ECC(Fld3dCiTexBlock *texBlock, Fld3dCiPlttDictEntry *entry);
int func_021C2EDC(Fld3dCiTexBlock *texBlock, const char *name);
int func_021C2F14(Fld3dCiTexBlock *texBlock, const char *name);
void func_021C2F50(char *dst, const char *src);
void func_021C2F84(void *playerStatus, Fld3dCi *ci, const char *texName, const char *plttName, u32 msgId, u32 centered);
void *func_021C30B8(void *gameSystem, Fld3dCi *ci, u32 nameMsgId);
void func_021C30D4(u32 unused);
void func_021C313C(Fld3dCi *ci, Fld3dCiEventWork *work);
void func_021C3158(Fld3dCi *ci);
void func_021C3198(void *task, u32 *done);
extern Fld3dCiStateFunc d_021DA128[];
extern u8 d_021DE3C8;
extern u8 d_021DE3D8;
extern const VecFx32 d_021DA6E8;
extern const VecFx32 d_021DA6D0;
extern const VecFx32 d_021DA6F4;
extern const VecFx32 d_021DA6DC;
extern const s16 d_020A1EB8[];
extern u32 d_021DA7F4[];
extern unsigned char abs_id_4A[];
extern const Fld3dCiBgMode d_021DA710;
extern char d_021DE3E4[];
extern char d_021DE3F4[];
extern char d_021DE404[];
extern char d_021DE40C[];
extern char d_021DE418[];
extern char d_021DE428[];
extern char d_021DE43C[];
extern char d_021DE448[];
extern Fld3dCiCue *d_021DA720[];
extern const Fld3dCiDispSetup d_021DA700;

/*
 * Runs the state table until a state returns other than 1.
 * Belongs to the grid event file (see cuts).
 */
void func_021C1988(void *work, u16 *state)
{
    if (state[0] != 0) {
        while (d_021DA128[(s16)state[1]](state) == 1)
            ;
    } else {
        func_021C16AC((u8 *)state);
    }
}

/* Belongs to the grid event file (see cuts). */
u32 func_021C19B4(u8 *work, u32 direction)
{
    u32 mmdl;
    u32 mapHandle;
    int gridX;
    int gridZ;

    mmdl = (u32)func_021A572C(work);
    mapHandle = (u32)func_0216D67C((void *)mmdl);
    gridX = func_0216D83C((void *)mmdl);
    gridX += func_021641E8(direction);
    gridZ = func_0216D86C((void *)mmdl);
    gridZ += func_021641F8(direction);
    return (u32)func_0216DDDC(mapHandle, (s16)gridX, (s16)gridZ, (u32)func_0216D8AC((void *)mmdl), (u32)1, 0);
}

FldParticle *func_021C1A08(u32 heapId)
{
    FldParticle *particle;

    particle = func_02030734(heapId, 0x10, 1, (const char *)&d_021DE3C8, 0x2e);
    particle->heapId = heapId;
    func_02050B80(heapId);
    particle->workBuffer = func_02030734(heapId, 0x4800, 1, (const char *)&d_021DE3C8, 0x34);
    return particle;
}

/*
 * Creates the effect instance and sets its two scale parameters.
 */
void *func_021C1A48(FldParticle *particle)
{
    u32 effectScale;
    u32 effectRange;
    void *effect;

    particle->effect = func_02050C04((int)particle->workBuffer, 0x4800, 1, particle->heapId);
    effect = func_02051788(particle->effect);
    effectScale = 1 << 12;
    effectRange = 0x384000;
    func_02048B60(effect, &effectScale);
    func_02048B6C(effect, &effectRange);
    return particle->effect;
}

void func_021C1A84(FldParticle *particle)
{
    void *effect = particle->effect;
    if (effect != 0) {
        func_02050DB8(effect);
        particle->effect = 0;
    }
}

/*
 * Loads a resource with the owner's heap id (tail call).
 */
void *func_021C1A98(FldParticle *particle, int kind, int resourceId)
{
    return (void *)func_0205121C(kind, resourceId, particle->heapId);
}

int func_021C1AA8(FldParticle *particle, u32 resource, u32 arg0, u32 arg1)
{
    return func_02051230((u32)particle->effect, resource, arg0, arg1);
}

/* Returns 1 when the effect is gone or finished. */
int func_021C1AB4(FldParticle *particle)
{
    if (particle->effect == 0)
        return 1;
    if (func_02051614((int **)particle->effect) == 0)
        return 1;
    return 0;
}

u32 func_021C1AD0(FldParticle *particle)
{
    func_021C1A84(particle);
    func_02050ED4();
    func_020307B0(particle->workBuffer);
    return func_020307B0(particle);
}

/*
 * Tail-call thunk: forwards to func_02050BE8 with no argument change.
 */
void func_021C1AEC(void)
{
    func_02050BE8();
}

static inline void *MakeCamera(int kind, int param1, int param2, int param3, int param4, int nearClip, int farClip, int scaleW, VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *target, int heapId)
{
    VecFx32 up = *upsrc;
    return func_02048A24(kind, param1, param2, param3, param4, nearClip, farClip, scaleW, pos, &up, target, heapId);
}

static inline void *MakePerspCamera(VecFx32 *pos, const VecFx32 *upsrc, VecFx32 *target, int heapId)
{
    return MakeCamera(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 0x1000, 0x400000, 0, pos, upsrc, target, heapId);
}

/*
 * note:     stack slots (high to low) pos1, tgt1, pos2, tgt2, up2, up1. The caller's block
 *           locals take the top slots in textual order; each up vector is an inline helper's
 *           local, and the first call reaching the helper one inline level deeper (through
 *           MakePerspCamera) is what puts up1 below up2. Both calls through MakeCamera directly: up1/up2
 *           swapped (2 bytes out). The zero targets need a brace initialiser in a declaration.
 */
Fld3dCi *func_021C1AF4(u32 heapId, FldParticle *particle)
{
    Fld3dCi *ci;

    ci = func_02030734(heapId, 0x138, 1, (const char *)&d_021DE3D8, 0x158);
    ci->gfxUnits = func_02047CFC(8, 2, heapId);
    ci->heapId = heapId;
    ci->particle = particle;
    ci->effectUnit = -1;
    {
        VecFx32 perspPos = d_021DA6E8;
        VecFx32 perspTarget = {0, 0, 0};
        ci->cameraPersp = MakePerspCamera(&perspPos, &d_021DA6D0, &perspTarget, heapId);
    }
    {
        VecFx32 orthoPos = d_021DA6F4;
        VecFx32 orthoTarget = {0, 0, 0};
        ci->cameraOrtho = MakeCamera(2, 0x30000, -0x30000, -0x40000, 0x40000, 0x1000, 0x400000, 0, &orthoPos, &d_021DA6DC, &orthoTarget, heapId);
    }
    ci->cameraSelect = 0;
    return ci;
}

/*
 * Releases the effect handles and frees the object (EXACT*: trailing pad).
 */
void func_021C1C04(Fld3dCi *ci)
{
    func_02048AC4(ci->cameraPersp);
    func_02048AC4(ci->cameraOrtho);
    func_02047E54(ci->gfxUnits);
    func_020307B0(ci);
}

/* Adds the sequence's resource table as a graphics unit and resets the draw status. */
int func_021C1C24(Fld3dCi *ci, Fld3dCiResource **resourceTable)
{
    ci->effectUnit = func_02047E88((u32)ci->gfxUnits, (u32)resourceTable);
    ci->status.scale.x = (1 << 12);
    ci->status.scale.y = (1 << 12);
    ci->status.scale.z = (1 << 12);
    func_0207ADC4((u32)&ci->status.rotate);
    ci->status.trans.x = 0;
    ci->status.trans.y = 0;
    ci->status.trans.z = 0;
    return 0;
}

/* Draws every object of the effect unit with the current status. */
void func_021C1C4C(Fld3dCi *ci)
{
    int first;
    int count;
    int object;
    u8 i;

    if (ci->cameraSelect == 0)
        func_02048AD0(ci->cameraPersp);
    else
        func_02048AD0(ci->cameraOrtho);
    if (ci->effectUnit != -1) {
        first = (int)func_020489F4(ci->gfxUnits, (u16)ci->effectUnit);
        count = (int)func_02048A00(ci->gfxUnits, (u16)ci->effectUnit);
        for (i = 0; i < count; i++) {
            object = (int)func_02048A18(ci->gfxUnits, (u16)(first + i));
            func_02047A60((void *)object, &ci->status);
        }
    }
}

/* Starts the game event of a cut-in sequence when there is memory for it. */
void *func_021C1CB0(void *gameSystem, Fld3dCi *ci, int sequenceId)
{
    void *event;

    if (func_0203038C(0x15) < d_021DA7F4[sequenceId])
        return 0;
    ci->started = 0;
    ci->finishState = 0;
    ci->frame = 0;
    ci->cueIndex = 0;
    ci->sequenceId = sequenceId;
    ci->extraTask = 0;
    ci->finishStep = 0;
    ci->cameraSelect = 0;
    event = func_020122C0(gameSystem, 0, func_021C1E7C, 0x40);
    func_021C313C(ci, func_020124E8(event));
    return event;
}

/* Starts the pokemon cut-in (sequence 3) with the pokemon description in the arguments. */
void *func_021C1D18(void *gameSystem, Fld3dCi *ci, int species, int form, int attr6E, int personality, int attr4C)
{
    Fld3dCiPokemon *pokemon;
    void *event;

    event = func_021C1CB0(gameSystem, ci, 3);
    if (event == 0)
        return 0;
    ci->extraTask = func_021C27F4;
    ci->finishStep = func_021C2854;
    pokemon = &ci->arg.pokemon;
    pokemon->attr6E = attr6E;
    ci->arg.pokemon.species = species;
    pokemon->personality = personality;
    pokemon->form = form;
    pokemon->attr4C = attr4C;
    pokemon->cryDelay = 5;
    pokemon->cryPending = 1;
    pokemon->cryFadeWait = 0x1e;
    return event;
}

/* Starts the pokemon cut-in for the party member at partyPos. */
void *func_021C1D68(void *gameSystem, Fld3dCi *ci, int partyPos)
{
    int mon;
    int species;
    int form;
    int attr6E;
    int personality;
    int attr4C;

    mon = (int)func_0201AB28(func_02012934(func_020120F4(gameSystem)), partyPos);
    species = func_02017E1C((void *)mon, 5, 0);
    form = func_02017E1C((void *)mon, 0x6f, 0);
    attr6E = func_02017E1C((void *)mon, 0x6e, 0);
    personality = func_02017EAC((void *)mon);
    attr4C = func_02017E1C((void *)mon, 0x4c, 0);
    return func_021C1D18(gameSystem, ci, species, form, attr6E, personality, attr4C);
}

/* Starts a name cut-in whose icon files come from a table row. */
void *func_021C1DCC(void *gameSystem, Fld3dCi *ci, int tableIndex, int fadeVariant)
{
    int *row;
    void *event;
    Fld3dCiEventWork *work;
    Fld3dCiIcon *icon;

    func_02034AC4((int)abs_id_4A);
    row = func_021F54E0(tableIndex);
    event = func_021C1CB0(gameSystem, ci, (u8)(*row));
    if (event == 0) {
        func_02034A5C((int)abs_id_4A);
        return 0;
    }
    work = func_020124E8(event);
    func_021C313C(ci, work);
    work->fadeVariant = fadeVariant;
    if (row[4] != 0)
        ci->extraTask = func_021C2D68;
    else
        ci->extraTask = 0;
    ci->finishStep = func_021C2CF4;
    ci->cameraSelect = 2;
    icon = &ci->arg.icon;
    icon->nameMsgId = row[3];
    icon->chrFile = row[1];
    icon->plttFile = row[2];
    if (row[4] == 1)
        icon->hasSecondName = 1;
    else
        icon->hasSecondName = 0;
    if (row[0] == 0xd && icon->hasSecondName != 0)
        icon->secondNameCentered = 1;
    else
        icon->secondNameCentered = 0;
    func_02034A5C((int)abs_id_4A);
    return event;
}

/* Main step of the cut-in game event: one state per call. */
int func_021C1E7C(void *event, int *state, Fld3dCiEventWork *work)
{
    Fld3dCi *ci;
    void *gameSystem;
    void *fieldMap;
    int doneB;
    int doneC;
    u32 modelSys;
    u32 particleSys;
    Fld3dCiBgMode bgMode;

    ci = work->ci;
    gameSystem = func_020124E4(event);
    fieldMap = func_0201210C(gameSystem);
    switch (*state) {
    case 0:
        if (work->hideFieldObjects)
            func_0216D9A0(func_02188C7C(fieldMap));
        func_021C27A4(ci);
        func_021C27C0(ci);
        if (func_021C2BD4(ci->sequenceId) == 0)
            func_02012374(event, func_020122C0(gameSystem, event, func_021C2B1C, 0));
        (*state)++;
        break;
    case 1:
        (*state)++;
        if (ci->sequenceId == 0xb || ci->sequenceId == 0x12) {
            func_0216DAC8(func_021A3074(func_02188CB4(fieldMap)), 1);
            break;
        }
        if (ci->sequenceId == 0x11) {
            u32 mmdl = (u32)func_0216DE94(func_02188C7C(fieldMap), (u16)ci->arg.pokemon.species);
            if (mmdl)
                func_0216CF2C(mmdl);
            break;
        }
    case 2:
        func_02189A58(fieldMap, 1);
        func_021C2764(ci);
        (*state)++;
        break;
    case 3:
        if (ci->captureDone == 0)
            break;
        func_0204047C(0, 0);
        func_0204047C(2, 1);
        bgMode = d_021DA710;
        func_0203FC28(&bgMode);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x4084;
        func_0207FDCC(8);
        func_0207D63C(0x04000050, 0, 4, 0, 0);
        func_02040588(2, 1);
        func_021A01A4(func_02188C64(fieldMap), 0);
        (*state)++;
        break;
    case 4:
        func_021C2320(event, ci, &work->seq, (u8)ci->sequenceId);
        func_02040588(2, 1);
        func_02040588(0, 1);
        func_02030830(ci->heapId);
        func_021899F8(fieldMap, 1);
        if (work->seq.darkenScreen)
            func_021C30D4(work->seq.darkenScreen);
        (*state)++;
        break;
    case 5:
        if (func_021C2BD4(ci->sequenceId))
            func_02012374(event, func_020122C0(gameSystem, event, func_021C2B98, 0));
        else
            func_02012374(event, func_020122C0(gameSystem, event, func_021C2B5C, 0));
        (*state)++;
        break;
    case 6:
        if (func_02005C64())
            break;
        (*state)++;
    case 7:
        {
            int doneA;
            int finished;
            ci->frame += 1;
            doneA = func_021C21B4(ci);
            doneB = func_021C223C(ci);
            doneC = func_021C22AC(ci);
            ci->startDone = doneA;
            ci->trackADone = doneB;
            ci->trackBDone = doneC;
            func_021C3158(ci);
            finished = 0;
            if (ci->finishStep)
                finished = ci->finishStep(event, ci);
            else if (ci->startDone && ci->trackADone && ci->trackBDone)
                finished = 1;
            if (finished == 0)
                break;
        }
        (*state)++;
        break;
    case 8:
        func_021899F8(fieldMap, 0);
        func_021C2484(ci, &work->seq);
        if (func_021C2BD4(ci->sequenceId)) {
            void *mmdlSys = func_021A3074(func_02188CB4(fieldMap));
            func_0216DAC8(mmdlSys, 0);
            func_0216D5E0((int)mmdlSys, 1);
            func_02189A58(fieldMap, 0);
        } else {
            func_02040588(0, 0);
            func_0207DD24(0, 0x1f, 0x7fff, 0, 0);
        }
        func_021A01A4(func_02188C64(fieldMap), 1);
        (*state)++;
        break;
    case 9:
        func_021A0568((u8 *)func_02188C60(fieldMap), 1);
        ci->displayRestoreDone = 0;
        func_020056A0(func_021C3198, &ci->displayRestoreDone, 0);
        (*state)++;
        break;
    case 10:
        if (ci->displayRestoreDone == 0)
            break;
        func_02030830(ci->heapId);
        modelSys = func_02188C54(fieldMap);
        particleSys = func_02188D20(fieldMap);
        func_02193068((char *)modelSys);
        func_021BC5D4((u8 *)particleSys);
        func_021904D0((u8 *)modelSys);
        *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & 0x43) | 0x1f18;
        func_020414AC(2);
        func_021C27CC(ci);
        func_021C27E8(ci);
        func_02189A58(fieldMap, 0);
        if (work->hideFieldObjects)
            func_0216D9E4(func_02188C7C(fieldMap));
        (*state)++;
        break;
    case 11:
        return 1;
    }
    return 0;
}

/* Counts down the two start delays and starts the animation tracks; 1 when both ran and the effect ended. */
int func_021C21B4(Fld3dCi *ci)
{
    if (ci->started == 0) {
        if (ci->trackStarted[0] == 0) {
            if (ci->startDelay[0] != 0) {
                (ci->startDelay[0])--;
            } else {
                func_021C24A8(ci, 0);
                ci->trackStarted[0] = 1;
            }
        }
        if (ci->trackStarted[1] == 0) {
            if (ci->startDelay[1] != 0) {
                (ci->startDelay[1])--;
            } else {
                func_021C24A8(ci, 1);
                ci->trackStarted[1] = 1;
            }
        }
        if (ci->trackStarted[0] != 0 && ci->trackStarted[1] != 0)
            ci->started = 1;
    } else if (func_021C1AB4(ci->particle) != 0) {
        return 1;
    }
    return 0;
}

/* Steps the first animation track after its wait delay; 1 when unused or finished. */
int func_021C223C(Fld3dCi *ci)
{
    int object;
    u8 i;
    int result;
    int count;

    if (ci->trackWatched[0] == 0)
        return 1;
    if (ci->waitDelay[0] != 0) {
        (ci->waitDelay[0])--;
    } else {
        object = func_02048A18(ci->gfxUnits, (int)func_020489F4(ci->gfxUnits, (u16)(ci->effectUnit)));
        count = func_0204779C((G3dObject *)object);
        for (i = 0; i < count; i++)
            result = func_020478B8((G3dObject *)object, i, 0x1000);
        if (result == 0)
            return 1;
    }
    return 0;
}

/* Same as above for the second animation track. */
int func_021C22AC(Fld3dCi *ci)
{
    int object;
    u8 i;
    int result;
    int count;

    if (ci->trackWatched[1] == 0)
        return 1;
    if (ci->waitDelay[1] != 0) {
        (ci->waitDelay[1])--;
    } else {
        object = (int)func_02048A18(ci->gfxUnits, (u16)((int)func_020489F4(ci->gfxUnits, (u16)(ci->effectUnit)) + 1));
        count = func_0204779C((G3dObject *)object);
        for (i = 0; i < count; i++)
            result = func_020478B8((G3dObject *)object, i, 0x1000);
        if (result == 0)
            return 1;
    }
    return 0;
}

/* Loads the sequence data and resets the animation state of the cut-in. */
void func_021C2320(void *event, Fld3dCi *ci, Fld3dCiSeq *seq, int sequenceId)
{
    int effectRes;
    u8 unit;
    int first;
    int unitCount;
    u8 j;
    int object;
    int animCount;
    int trackKind;

    ci->effect = func_021C1A48(ci->particle);
    func_021C24F0(seq, sequenceId, ci->heapId);
    func_021C1C24(ci, &seq->resourceTable);
    if (seq->effectResId != 0xFFFF) {
        effectRes = (int)func_021C1A98(ci->particle, 0x73, seq->effectResId);
        func_021C1AA8(ci->particle, effectRes, 1, 0);
    } else {
        effectRes = 0;
    }
    first = (int)func_020489F4(ci->gfxUnits, (u16)ci->effectUnit);
    unitCount = (int)func_02048A00(ci->gfxUnits, (u16)ci->effectUnit);
    for (unit = 0; unit < unitCount; unit++) {
        object = (int)func_02048A18(ci->gfxUnits, (u16)(first + unit));
        animCount = func_0204779C((G3dObject *)object);
        for (j = 0; j < animCount; j++)
            func_020477A4((G3dObject *)object, (u8)j);
    }
    ci->startDelay[0] = seq->startDelay[0];
    ci->startDelay[1] = seq->startDelay[1];
    ci->waitDelay[0] = seq->waitDelay[0];
    ci->waitDelay[1] = seq->waitDelay[1];
    if (effectRes != 0)
        trackKind = func_02051B04((void *)effectRes);
    else
        trackKind = 0;
    if (trackKind == 2) {
        ci->trackStarted[0] = 0;
        ci->trackStarted[1] = 0;
    } else if (trackKind == 1) {
        ci->trackStarted[0] = 0;
        ci->trackStarted[1] = 1;
    } else {
        ci->trackStarted[0] = 1;
        ci->trackStarted[1] = 1;
    }
    ci->trackWatched[0] = 0;
    ci->trackWatched[1] = 0;
    if (seq->trackBCount != 0)
        ci->trackWatched[0] = 1;
    if (seq->trackCCount != 0)
        ci->trackWatched[1] = 1;
    if (ci->extraTask != 0) {
        object = (int)func_020124E4(event);
        func_02012374(event, func_020122C0((void *)object, event, (void *)(ci->extraTask), (int)0));
    }
}

/* Frees the sequence data, deletes the effect unit and the effect. */
void func_021C2484(Fld3dCi *ci, Fld3dCiSeq *seq)
{
    func_021C2734(seq);
    func_020480E4(ci->gfxUnits, (u16)ci->effectUnit);
    ci->effectUnit = (~0);
    func_021C1A84(ci->particle);
}

/*
 * EXACT*: the 72-byte listing extent runs on into the unlabelled leaf
 * func_021C24BC (ov021_func_021C24BC.c), whose EXACT entry attests the
 * pool word 0x021C24BD as matched.
 */
void func_021C24A8(Fld3dCi *ci, int track)
{
    func_020515CC((int *)(ci->effect), track, (int)func_021C24BC, 0);
}

/*
 * Unlabelled thumb leaf (push {r4} only), reached through the pool word
 * 0x021C24BD in func_021C24A8. Char-pointer offsets give the same bytes
 * scheduled differently (34 differ); the struct-typed accesses keep the
 * zero-initialiser stores ahead of the loads, as in the original.
 */
void func_021C24BC(Fld3dCiFollow *follow)
{
    VecFx32 offset = { 0, 0, 0 };
    offset.z = 0x40;
    follow->pos.x = offset.x + (*follow->target)->pos.x;
    follow->pos.y = offset.y + (*follow->target)->pos.y;
    follow->pos.z = offset.z + (*follow->target)->pos.z;
}

/* Reads sequence record sequenceId of archive 0x75 and builds the resource and track tables. */
void func_021C24F0(Fld3dCiSeq *seq, u32 sequenceId, u32 heapId)
{
    Fld3dCiSeqFile file;
    u16 ids[8];
    u8 trackACount, trackBCount, trackCCount, total, baseB, baseC;
    u8 i, j, n;

    func_02048F4C(&file, 0x75, sequenceId);
    trackACount = 0;
    for (i = 0; i < 2; i++) {
        if (file.trackA[i] != 0xFFFF) {
            trackACount++;
        }
    }
    trackCCount = 0;
    trackBCount = 0;
    for (i = 0; i < 4; i++) {
        if (file.trackB[i] != 0xFFFF) {
            trackBCount++;
        }
    }
    for (i = 0; i < 4; i++) {
        if (file.trackC[i] != 0xFFFF) {
            trackCCount++;
        }
    }
    baseB = 0 + trackACount;
    baseC = baseB + trackBCount;
    total = trackACount + trackBCount + trackCCount;
    if (total != 0) {
        seq->resources = func_02030734(heapId, total * 12, 1, (const char *)&d_021DE3D8, 0x566);
    }
    if (trackACount != 0) {
        seq->tracks = func_02030734(heapId, trackACount * 16, 1, (const char *)&d_021DE3D8, 0x56a);
    }
    if (trackBCount != 0) {
        seq->refsB = func_02030734(heapId, trackBCount * 4, 1, (const char *)&d_021DE3D8, 0x56e);
    }
    if (trackCCount != 0) {
        seq->refsC = func_02030734(heapId, trackCCount * 4, 1, (const char *)&d_021DE3D8, 0x572);
    }
    seq->total = total;
    seq->trackACount = trackACount;
    seq->trackBCount = trackBCount;
    seq->trackCCount = trackCCount;
    seq->startDelay[0] = file.startDelay[0];
    seq->startDelay[1] = file.startDelay[1];
    seq->waitDelay[0] = file.waitDelay[0];
    seq->waitDelay[1] = file.waitDelay[1];
    ids[0] = file.trackA[0];
    ids[1] = file.trackA[1];
    ids[2] = file.trackB[0];
    ids[3] = file.trackB[1];
    ids[4] = file.trackB[2];
    ids[5] = file.trackC[0];
    ids[6] = file.trackC[1];
    ids[7] = file.trackC[2];
    n = 0;
    for (j = 0; j < 8; j++) {
        if (ids[j] != 0xFFFF) {
            seq->resources[n].kind = 0x73;
            seq->resources[n].id = ids[j];
            seq->resources[n].value = 0;
            n++;
        }
    }
    for (i = 0; i < trackBCount; i++) {
        seq->refsB[i].index = baseB + i;
        seq->refsB[i].zero = 0;
    }
    for (i = 0; i < trackCCount; i++) {
        seq->refsC[i].index = baseC + i;
        seq->refsC[i].zero = 0;
    }
    for (i = 0; i < trackACount; i++) {
        seq->tracks[i].index = 0 + i;
        seq->tracks[i].zero = 0;
        seq->tracks[i].trackIndex = 0 + i;
    }
    if (trackACount >= 1) {
        seq->tracks[0].refs = seq->refsB;
        seq->tracks[0].refCount = trackBCount;
    }
    if (trackACount >= 2) {
        seq->tracks[1].refs = seq->refsC;
        seq->tracks[1].refCount = trackCCount;
    }
    seq->resourceTable = seq->resources;
    seq->resourceCount = total;
    seq->trackTableCount = trackACount;
    seq->trackTable = seq->tracks;
    seq->effectResId = file.effectResId;
    seq->darkenScreen = file.darkenScreen;
}

/*
 * Frees the four optional buffers (EXACT*: trailing pad).
 */
void func_021C2734(Fld3dCiSeq *seq)
{
    if (seq->refsB != 0)
        func_020307B0(seq->refsB);
    if (seq->refsC != 0)
        func_020307B0(seq->refsC);
    if (seq->tracks != 0)
        func_020307B0(seq->tracks);
    if (seq->resources != 0)
        func_020307B0(seq->resources);
}

/*
 * Clears the capture flag and starts the capture task.
 */
void func_021C2764(Fld3dCi *ci)
{
    ci->captureDone = 0;
    func_0208068C(8);
    func_020056A0(func_021C2784, &ci->captureDone, 0);
}

/*
 * VBlank task: arms display capture, ends itself, flags completion.
 */
void func_021C2784(void *task, u32 *done)
{
    *(volatile u32 *)0x04000064 = 0x81330010;
    func_02030EAC(task);
    if (done != 0)
        *done = 1;
}

/*
 * Saves the four layer priorities.
 */
void func_021C27A4(Fld3dCi *ci)
{
    int i;
    for (i = 0; i < 4; i++)
        ci->savedLayerPriority[i] = func_020416D4((u8)i);
}

void func_021C27C0(Fld3dCi *ci)
{
    ci->savedVisiblePlanes = func_02043658();
}

/*
 * Restores the four saved layer priorities (EXACT*: unlabelled follower).
 */
void func_021C27CC(Fld3dCi *ci)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0204047C((u8)i, ci->savedLayerPriority[i]);
}

void func_021C27E8(Fld3dCi *ci)
{
    func_02043534(ci->savedVisiblePlanes);
}

/* Extra task of the pokemon cut-in: builds the pokemon icon texture, then frees its resources. */
int func_021C27F4(void *event, int *state)
{
    Fld3dCi *ci;
    Fld3dCiEventWork *parentWork;

    parentWork = func_020124E8(func_020124F0(event));
    ci = parentWork->ci;
    func_0201210C(func_020124E4(event));
    switch (*state) {
    case 0:
        func_021C2918(ci);
        (*state)++;
        break;
    case 1:
        func_020437AC(ci->canvas);
        func_020307B0(ci->chrRes);
        func_020307B0(ci->plttRes);
        (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}

/* Finish step of the pokemon cut-in: plays the cry after its delay and waits for it to fade. */
int func_021C2854(void *event, Fld3dCi *ci)
{
    int done;
    Fld3dCiPokemon *pokemon;
    char voiceBuf[4];

    pokemon = &ci->arg.pokemon;
    if (pokemon->cryPending != 0 && pokemon->cryDelay != 0) {
        (pokemon->cryDelay)--;
        if (pokemon->cryDelay == 0) {
            if (pokemon->species == 0x1b9) {
                func_02006CAC((void **)voiceBuf);
                pokemon->cryHandle = func_02006984(pokemon->species, pokemon->form, 0x40, 0, 0, 0, 0, (unsigned int)voiceBuf);
            } else {
                pokemon->cryHandle = func_02006984(pokemon->species, pokemon->form, 0x40, 0, 0, 0, 0, 0);
            }
        }
        pokemon->cryFadeWait = 0x1e;
        return 0;
    }
    done = 0;
    if (pokemon->cryDelay == 0) {
        if (func_02006650() == 0) {
            done = 1;
        } else if (pokemon->cryFadeWait != 0) {
            (pokemon->cryFadeWait)--;
        } else if (func_02006B20(pokemon->cryHandle) > 0) {
            func_02006A8C(pokemon->cryHandle, done - 16);
        } else {
            func_020065D8();
            done = 1;
        }
    }
    if (ci->startDone != 0 && ci->trackADone != 0 && ci->trackBDone != 0 && done != 0)
        return 1;
    return 0;
}

/*
 * Twin of ov195 func_0220685C (same tile-copy body). The far argument block
 * at +0x9C needs a local pointer (args = ci->arg.args), and the two size calls
 * must land in int locals before the (u16) << 3 conversions.
 */
void func_021C2918(Fld3dCi *ci)
{
    u16 heapId;
    u8 *tileBuf;
    int j;
    u32 texOffset;
    u32 plttOffset;
    u8 *chrSrc;
    u32 chrFile;
    u32 plttFile;
    void *texBlock;
    u32 *args;
    int texSize;
    int plttSize;
    int i;
    int tile;

    heapId = ci->heapId;
    ci->canvas = func_02043678(16, 16, 32, heapId);
    tile = 0;
    texBlock = (void *)func_02048A0C(ci->gfxUnits, 0);
    texSize = func_02047388(texBlock);
    plttSize = func_020473B8(texBlock);
    texOffset = (u16)texSize << 3;
    plttOffset = (u16)plttSize << 3;
    args = ci->arg.args;
    chrFile = func_0202D064(func_0202D060(), args[0], args[1], args[2], args[3], 0, args[4]);
    plttFile = func_0202D0D4(func_0202D060(), args[0], args[1], args[2], args[3], 0, args[4]);
    ci->chr = 0;
    ci->pltt = 0;
    ci->chrRes = func_02049E34(func_0202D060(), chrFile, 1, (u32)(&ci->chr), heapId);
    ci->plttRes = func_02049F34(func_0202D060(), plttFile, (u32)(&ci->pltt), heapId);
    chrSrc = ci->chr->raw;
    tileBuf = func_020437D4(ci->canvas);
    func_02082A7C(0, tileBuf, 0x2000);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    for (j = 0; j < 8; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 0; i < 8; i++) {
            func_02082A90(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    for (j = 8; j < 12; j++) {
        for (i = 8; i < 12; i++) {
            func_02082A90(chrSrc + tile * 32, tileBuf + 0x440 + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    func_02044F64(ci->canvas, 0, heapId);
    func_02061CA4(0, texOffset, (u32)func_020437D4(ci->canvas), 0x2000);
    func_02061CA4((void *)1, plttOffset, (u32)ci->pltt->raw, 0x20);
    func_02030830(ci->heapId);
}

/* Fade task: fades the screen out. */
int func_021C2B1C(void *event, int *state)
{
    func_0201210C(func_020124E4(event));
    switch (*state) {
    case 0:
        func_0204E720(4, 0, 0x10, -1);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Fade-in task: start the fade, then wait for it to finish.
 */
int func_021C2B5C(void *event, int *state)
{
    func_0201210C(func_020124E4(event));
    switch (*state) {
    case 0:
        func_0204E720(4, 0x10, 0, -1);
        (*state)++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}

int func_021C2B98(void *event, u32 *state)
{
    func_0201210C(func_020124E4(event));
    switch (state[0]) {
    case 0:
        func_0204E720(3, 0x10, 0, 0);
        state[0]++;
        break;
    case 1:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}

/*
 * Unlabelled leaf: true for the two ids 0xC and 0x13.
 */
int func_021C2BD4(u16 sequenceId)
{
    if (sequenceId == 0xc || sequenceId == 0x13)
        return 1;
    return 0;
}

/*
 * Sibling of func_021C2918 (same object layout at +0x88..+0x98), 16x16
 * tile copy with archive 0xB4 and file ids passed in.
 */
void func_021C2BE4(Fld3dCi *ci, const char *texName, const char *plttName, u32 chrFile, u32 plttFile)
{
    u32 texOffset;
    u32 plttOffset;
    u16 heapId;
    u8 *tileBuf;
    int j;
    void *texBlock;
    void *modelRes;
    u8 *chrSrc;
    int i;
    int tile;

    heapId = ci->heapId;
    tile = 0;
    texBlock = (void *)func_02048A0C(ci->gfxUnits, 0);
    func_02047388(texBlock);
    func_020473B8(texBlock);
    modelRes = func_0206E964(func_02046F48(texBlock));
    texOffset = func_021C2EDC(modelRes, texName);
    plttOffset = func_021C2F14(modelRes, plttName);
    ci->chr = 0;
    ci->pltt = 0;
    ci->chrRes = func_02049DB4(0xb4, chrFile, 1, (u32)(&ci->chr), heapId);
    ci->plttRes = func_02049F34(0xb4, plttFile, (u32)(&ci->pltt), heapId);
    chrSrc = ci->chr->raw;
    tileBuf = func_020437D4(ci->canvas);
    func_02082A7C(0, tileBuf, 0x2000);
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            func_02082A90(chrSrc + tile * 32, tileBuf + (i + j * 16) * 32, 32);
            tile++;
        }
    }
    func_02044F64(ci->canvas, 0, heapId);
    func_02061CA4(0, texOffset, (u32)func_020437D4(ci->canvas), 0x2000);
    func_02061CA4((void *)1, plttOffset, (u32)ci->pltt->raw, 0x20);
    func_02030830(ci->heapId);
}

/*
 * func_020124E8 takes the event (the first parameter, still in r0 on the
 * path to the call): that is what keeps r0 live and puts the switch value
 * in r1.
 */
int func_021C2CF4(void *event, Fld3dCi *ci)
{
    switch (ci->finishState) {
    case 0:
        if (ci->startDone != 0 && ci->trackADone != 0 && ci->trackBDone != 0)
            ci->finishState = ci->finishState + 1;
        break;
    case 1:
        func_0204E720(((Fld3dCiEventWork *)func_020124E8(event))->fadeVariant != 0 ? 0xC : 3, 0, 0x10, -1);
        ci->finishState += 1;
    case 2:
        if (func_0204E804() == 0)
            return 1;
        break;
    }
    return 0;
}

/* Extra task of the name cut-in: draws the name texture, then the optional second one. */
int func_021C2D68(void *event, int *state)
{
    Fld3dCiEventWork *parentWork;
    void *gameSystem;
    void *playerStatus;
    Fld3dCi *ci;
    Fld3dCiIcon *icon;
    u32 chrFile;
    u32 plttFile;

    parentWork = func_020124E8(func_020124F0(event));
    gameSystem = func_020124E4(event);
    playerStatus = func_02012944(func_020120F4(gameSystem));
    ci = parentWork->ci;
    func_0201210C(gameSystem);
    icon = &ci->arg.icon;
    switch (*state) {
    case 0:
        ci->canvas = func_02043678(16, 16, 32, ci->heapId);
        func_021C2BE4(ci, d_021DE3E4, d_021DE3F4, icon->chrFile, icon->plttFile);
        (*state)++;
        break;
    case 1:
        func_020437AC(ci->canvas);
        func_020307B0(ci->chrRes);
        func_020307B0(ci->plttRes);
        func_021C2F84(playerStatus, ci, d_021DE404, d_021DE40C, icon->nameMsgId, 0);
        (*state)++;
        break;
    case 2:
        if (icon->hasSecondName == 0) {
            *state = 4;
            break;
        }
        ci->canvas = func_02043678(16, 16, 32, ci->heapId);
        if (func_02008550(playerStatus) == 0) {
            chrFile = 0;
            plttFile = 0x16;
        } else {
            chrFile = 1;
            plttFile = 0x17;
        }
        func_021C2BE4(ci, d_021DE418, d_021DE428, chrFile, plttFile);
        (*state)++;
        break;
    case 3:
        func_020437AC(ci->canvas);
        func_020307B0(ci->chrRes);
        func_020307B0(ci->plttRes);
        func_021C2F84(playerStatus, ci, d_021DE43C, d_021DE448, 0, icon->secondNameCentered);
        (*state)++;
        break;
    case 4:
        ci->status.trans.x = 0;
        ci->status.trans.y = 0;
        ci->status.trans.z = 0xFFD44000;
        func_02046BE0(0, 0);
        return 1;
    }
    return 0;
}

/* Byte offset of a texture's data inside the model resource. */
int func_021C2EBC(Fld3dCiTexBlock *texBlock, Fld3dCiTexDictEntry *entry)
{
    return (((entry->dataWord << 16) >> 13) + ((texBlock->texDataWord << 16) >> 13));
}

/* Byte offset of a palette's data inside the model resource. */
int func_021C2ECC(Fld3dCiTexBlock *texBlock, Fld3dCiPlttDictEntry *entry)
{
    return ((entry->dataWord << 3) + ((texBlock->plttDataWord << 16) >> 13));
}

/*
 * Looks a texture up by name and returns its data offset (EXACT*: pad).
 */
int func_021C2EDC(Fld3dCiTexBlock *texBlock, const char *name)
{
    Fld3dCiNameKey key;
    int entry;

    func_021C2F50((char *)&key, name);
    if (texBlock != 0)
        entry = func_0206E62C((u8 *)texBlock + 0x3C, &key);
    else
        entry = 0;
    if (entry == 0)
        return 0;
    return func_021C2EBC(texBlock, (Fld3dCiTexDictEntry *)entry);
}

/* Looks a palette up by name and returns its data offset. */
int func_021C2F14(Fld3dCiTexBlock *texBlock, const char *name)
{
    Fld3dCiNameKey key;
    int entry;

    func_021C2F50((char *)&key, name);
    if (texBlock != 0 && texBlock->plttDictOffset != 0)
        entry = func_0206E62C((u8 *)texBlock + texBlock->plttDictOffset, &key);
    else
        entry = 0;
    if (entry == 0)
        return 0;
    return func_021C2ECC(texBlock, (Fld3dCiPlttDictEntry *)entry);
}

/*
 * Copies a name into a zeroed 16-byte request block (EXACT*: pad).
 */
void func_021C2F50(char *dst, const char *src)
{
    int length = func_0208CC78(src);
    u8 i;
    for (i = 0; i < 4; i++)
        ((u32 *)dst)[i] = 0;
    for (i = 0; i < length; i++)
        dst[i] = src[i];
}

/* Renders a message into the name texture and its palette. */
void func_021C2F84(void *playerStatus, Fld3dCi *ci, const char *texName, const char *plttName, u32 msgId, u32 centered)
{
    u8 texKey[0x14];
    void *wordSet;
    void *font;
    void *rawMsg;
    void *msgBank;
    void *texBlock;
    u16 heapId;
    void *text;
    int xOffset;
    u16 *palette;

    texBlock = (void *)func_02048A0C(ci->gfxUnits, 0);
    heapId = ci->heapId;
    msgBank = func_02045B38(0, 2, 0xb0, heapId);
    if (msgId == 0) {
        wordSet = func_0201EC64((u16)((heapId & 0x7FFF) | 0x8000));
        text = func_020457B0(8, (heapId & 0x7FFF) | 0x8000);
        rawMsg = func_02045EC0(msgBank, msgId);
        func_0201F02C(wordSet, 0, playerStatus);
        func_0201F250(wordSet, text, rawMsg);
        func_02045808(rawMsg);
        func_0201ED04(wordSet);
    } else {
        rawMsg = func_02045EC0(msgBank, msgId);
        text = func_020457B0(0x10, (heapId & 0x7FFF) | 0x8000);
        func_0201F4A0(text, rawMsg);
        func_02045808(rawMsg);
    }
    xOffset = 0;
    if (centered != 0) {
        font = func_0201D7EC(0x17, 0, 0, 0, heapId);
        xOffset = func_0201D304(text, (u32)font, 0);
        func_0201D83C(font);
        xOffset = 0x3c - xOffset;
        if (xOffset < 0)
            xOffset = 0;
    }
    ci->plttRes = func_02049F34(0x17, 5, (u32)(&ci->pltt), heapId);
    palette = ci->pltt->raw;
    palette[1] = 0x7FFF;
    palette[2] = 0;
    func_0216FAB4(texBlock, texName, palette, plttName, (u32)text, xOffset, 0, 0x440, heapId, texKey);
    func_020307B0(ci->plttRes);
    func_020307B0(text);
    func_02045C04(msgBank);
}

/*
 * Starts the name cut-in 0x11 with its name message id (EXACT*: pad).
 */
void *func_021C30B8(void *gameSystem, Fld3dCi *ci, u32 nameMsgId)
{
    void *event = func_021C1CB0(gameSystem, ci, 0x11);
    if (event == 0)
        return 0;
    ci->arg.icon.nameMsgId = nameMsgId;
    return event;
}

/*
 * Halves every RGB555 colour in LCDC VRAM bank 0x06860000 (0xC000 halfwords)
 * to darken the captured screen. The parameter is unused (the caller passes
 * one). The channels are extracted into u8 locals (b, g, r, a), then halved
 * as separate `x = x >> 1` statements in b, g, r order; that keeps every
 * channel in its own register so the scheduler interleaves the four chains,
 * and the halving order picks which truncation is scheduled early. Casts
 * inline in the OR expression serialise the chains instead.
 */
void func_021C30D4(u32 unused)
{
    int oldBankState = func_020808F4();
    u16 *pixel = (u16 *)0x06860000;
    int i;
    for (i = 0; i < 0xC000; i++) {
        u16 color = *pixel;
        u8 b = (color >> 10) & 0x1F;
        u8 g = (color >> 5) & 0x1F;
        u8 r = color & 0x1F;
        u8 a = (color >> 15) & 1;
        b = b >> 1;
        g = g >> 1;
        r = r >> 1;
        *pixel = (a << 15) | (b << 10) | (g << 5) | r;
        pixel++;
    }
    func_0207FDCC(oldBankState);
}

/*
 * Clears a 0x40-byte event work and stores its owner (EXACT*: pad).
 */
void func_021C313C(Fld3dCi *ci, Fld3dCiEventWork *work)
{
    func_02082BCC(work, 0, 0x40);
    work->ci = ci;
    work->hideFieldObjects = 0;
    work->fadeVariant = 0;
}

/*
 * Plays the next sound effect of the current cue table when its frame is
 * reached.
 */
void func_021C3158(Fld3dCi *ci)
{
    Fld3dCiCue *cues = d_021DA720[ci->sequenceId];
    if (cues[ci->cueIndex].soundId != -1 && ci->frame == cues[ci->cueIndex].frame) {
        func_020061E4(cues[ci->cueIndex].soundId);
        (ci->cueIndex)++;
    }
}

/*
 * VBlank task: applies the saved display setup, ends itself, flags completion.
 */
void func_021C3198(void *task, u32 *done)
{
    Fld3dCiDispSetup setup;
    func_02040588(0, 1);
    setup = d_021DA700;
    func_0203FC28(&setup);
    func_02030EAC(task);
    if (done != 0)
        *done = 1;
}
