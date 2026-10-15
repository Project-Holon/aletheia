/*
 * function: GFL_NET_STATE_InitRandom
 * address:  0x0203AE20
 * packet:   pkt_0203AE20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_GetMacAddress  0x02087C6C  arm
 *   RTC_GetDateTime     0x020889C0  arm
 *   func_0203F034     0x0203F034  arm
 *   func_0203F0A8     0x0203F0A8  arm
 *   g_02FFFC3C        0x02FFFC3C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_STATE_InitRandom.c  *       --func GFL_NET_STATE_InitRandom --addr 0x0203AE20 --cc 1.1p1 --arm
 *
 * net_state.c RNG seeder.  Mixes the MAC with the RTC date/time and the
 * system word 0x02FFFC3C, seeds func_0203F034, draws two words into one
 * u64 seed, and initialises a NitroSDK MATHRandContext64 with the SDK's
 * own MATH_InitRand64 inline (x = seed, mul 0x5D588B656C078965, add
 * 0x269EC3).  Wave 14 closed the 8-byte tail tie of
 * docs/notes/pkt_0203AE20.c.txt: +0x08..+0x14 are two u64 members, not
 * four u32 words, so the constants are stored as u64 pairs.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

static inline void MATH_InitRand64(MATHRandContext64 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}

extern void OS_GetMacAddress(u8 *p);
struct RTCDate;
struct RTCTime;
extern int RTC_GetDateTime(struct RTCDate *date, struct RTCTime *time);
extern void func_0203F034(u32 seed);
extern u32 func_0203F0A8(void);
extern u32 g_02FFFC3C;
struct Date { u32 year; u32 mon; u32 day; u32 wday; };
struct Time { u32 hour; u32 min; u32 sec; };

void GFL_NET_STATE_InitRandom(MATHRandContext64 *o)
{
  struct Date d;
  struct Time t;
  u8 mac[6];
  u32 seed;
  OS_GetMacAddress(mac);
  RTC_GetDateTime((struct RTCDate *)(&d), (struct RTCTime *)(&t));
  seed = ((d.year + ((d.day * (d.mon << 8)) << 16)) + (t.hour << 16)) + ((t.min + t.sec) << 24);
  seed = seed + (mac[5] + ((mac[3] << 16) + (mac[4] << 8)));
  seed = seed + g_02FFFC3C;
  func_0203F034(seed);
  {
    u32 hi = func_0203F0A8();
    MATH_InitRand64(o, (((u64) hi) << 32) + func_0203F0A8());
  }
}
