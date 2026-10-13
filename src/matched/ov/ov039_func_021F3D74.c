/*
 * function: func_021F3D74
 * address: 0x021F3D74
 * packet: pkt_ov039_021F3D74
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02028A7C 0x02028A7C thumb
 *   FIELD_SOUND_SYSTEM_TransferSlot 0x02028B18 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct SoundSys2;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern void func_02028A7C(struct SoundSys2 *p, u32 id);
extern void FIELD_SOUND_SYSTEM_TransferSlot(struct SoundSys2 *p, u32 id, u32 who);
void func_021F3D74(u32 a) { struct SoundSys2 *p; p = (struct SoundSys2 *)func_02012A30((const struct BigObj *)func_020120F4((const struct Ctx *)a)); func_02028A7C(p, 0x68a); FIELD_SOUND_SYSTEM_TransferSlot(p, 0x68a, 0); }
