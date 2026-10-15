/*
 * function: date2sec
 * address:  0x0216003C
 * packet:   pkt_ov009_0216003C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      date2sec (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   RTC_GetDate  0x02088864  arm
 *   RTC_GetTime  0x0208890C  arm
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 */

typedef struct {
	int year;
	int month;
	int day;
	int week;
} RTCDate;

typedef struct {
	int hour;
	int minute;
	int second;
} RTCTime;

struct RTCDate;
struct RTCTime;
extern int RTC_GetDate(struct RTCDate *date);
extern int RTC_GetTime(struct RTCTime *time);
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);

unsigned long date2sec(void)
{
	unsigned long sec;
	RTCDate date;
	RTCTime time;

	RTC_GetDate((struct RTCDate *)(&date));
	RTC_GetTime((struct RTCTime *)(&time));
	sec = RTC_ConvertDateTimeToSecond((struct RTCDate *)(&date), (struct RTCTime *)(&time));
	return sec + 946684800;
}
