// Dependencies
#include <FastLED.h>

// Defines
#define COUNT_LEDS (14)
#define ARD_PIN_LED_DATA (5)

// LEDs
CRGB leds[COUNT_LEDS];

// Custom Data Types
enum sg_digit_type_e {
  SG_DIGIT_TYPE_0,
  SG_DIGIT_TYPE_1,
  SG_DIGIT_TYPE_2,
  SG_DIGIT_TYPE_3,
  SG_DIGIT_TYPE_4,
  SG_DIGIT_TYPE_5,
  SG_DIGIT_TYPE_6,
  SG_DIGIT_TYPE_7,
  SG_DIGIT_TYPE_8,
  SG_DIGIT_TYPE_9,
  SG_DIGIT_TYPE_COUNT
};

enum sg_segment_type_e {
  SG_SEGMENT_TYPE_FLOOR,
  SG_SEGMENT_TYPE_BOTTOM_LEFT,
  SG_SEGMENT_TYPE_BOTTOM_RIGHT,
  SG_SEGMENT_TYPE_CENTER,
  SG_SEGMENT_TYPE_TOP_LEFT,
  SG_SEGMENT_TYPE_TOP_RIGHT,
  SG_SEGMENT_TYPE_CEILING
};

struct sg_digit_segments {
  enum sg_segment_type_e segments[7];
  int segment_count;
};

struct sg_segment_led_indices {
  int indices[2];
};

// Interface Forward Declarations
static void render_digit(enum sg_digit_type_e digit_type);
struct sg_digit_segments digit_type_segments(enum sg_digit_type_e digit_type);
struct sg_segment_led_indices digit_led_indices(enum sg_segment_type_e segment_type);
void clear_leds(void)
{
  for (int i_led = 0; i_led < COUNT_LEDS; ++i_led)
    leds[i_led] = CRGB::Blue;
}

// Interface Implementations
static void render_digit(enum sg_digit_type_e digit_type) {
  const struct sg_digit_segments DIGIT_SEGMENTS = digit_type_segments(digit_type);
  for (int i_digit_segment = 0; i_digit_segment < DIGIT_SEGMENTS.segment_count; ++i_digit_segment)
  {
    const struct sg_segment_led_indices DIGIT_LED_INDICES = digit_led_indices(DIGIT_SEGMENTS.segments[i_digit_segment]);
    for (int i_led = 0; i_led < 2; ++i_led)
    {
      leds[DIGIT_LED_INDICES.indices[i_led]] = CRGB::Yellow;
    }
  }
}

struct sg_digit_segments digit_type_segments(enum sg_digit_type_e digit_type) {
  struct sg_digit_segments ds;

  switch (digit_type) {
    case SG_DIGIT_TYPE_0:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_FLOOR;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      break;
    case SG_DIGIT_TYPE_1:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      break;
    case SG_DIGIT_TYPE_2:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_FLOOR;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CENTER;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      break;
    case SG_DIGIT_TYPE_3:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_FLOOR;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CENTER;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      break;
    case SG_DIGIT_TYPE_4:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CENTER;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      break;
    case SG_DIGIT_TYPE_5:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_FLOOR;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CENTER;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_LEFT;
      break;
    case SG_DIGIT_TYPE_6:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_FLOOR;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CENTER;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_LEFT;
      break;
    case SG_DIGIT_TYPE_7:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      break;
    case SG_DIGIT_TYPE_8:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_FLOOR;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CENTER;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      break;
    case SG_DIGIT_TYPE_9:
      ds.segment_count = 0;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_FLOOR;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CENTER;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_CEILING;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_BOTTOM_RIGHT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_LEFT;
      ds.segments[ds.segment_count++] = SG_SEGMENT_TYPE_TOP_RIGHT;
      break;
    default:
      ds.segment_count = 0;
  }

  return ds;
}

struct sg_segment_led_indices digit_led_indices(enum sg_segment_type_e segment_type)
{
  struct sg_segment_led_indices dli;

  switch (segment_type)
  {
    case SG_SEGMENT_TYPE_FLOOR:
      dli.indices[0] = 4;
      dli.indices[1] = 5;
      break;
    case SG_SEGMENT_TYPE_BOTTOM_LEFT:
      dli.indices[0] = 2;
      dli.indices[1] = 3;
      break;
    case SG_SEGMENT_TYPE_BOTTOM_RIGHT:
      dli.indices[0] = 0;
      dli.indices[1] = 1;
      break;
    case SG_SEGMENT_TYPE_CENTER:
      dli.indices[0] = 6;
      dli.indices[1] = 7;
      break;
    case SG_SEGMENT_TYPE_TOP_LEFT:
      dli.indices[0] = 10;
      dli.indices[1] = 11;
      break;
    case SG_SEGMENT_TYPE_TOP_RIGHT:
      dli.indices[0] = 8;
      dli.indices[1] = 9;
      break;
    case SG_SEGMENT_TYPE_CEILING:
      dli.indices[0] = 12;
      dli.indices[1] = 13;
      break;
  }

  return dli;
}

// Entry point
void setup() {
  // Serial
  Serial.begin(9600);

  // Initialize LEDs
  FastLED.addLeds<WS2812, ARD_PIN_LED_DATA>(leds, COUNT_LEDS);
  FastLED.setBrightness(100);
}

// Loop
void loop() {
  // Render scene
  for (int digit_type = 0; digit_type < SG_DIGIT_TYPE_COUNT; ++digit_type)
  {
    clear_leds();

    // Render a digit onto LED strip
    render_digit(digit_type);
    FastLED.show();
    Serial.println(digit_type);

    // Wait
    delay(1000);
  }
}
