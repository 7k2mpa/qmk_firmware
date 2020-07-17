#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

#include "7k2mpa.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _LLOWER 2
#define _RLOWER 3
#define _RAISE 4
#define _NUMPAD 5
#define _MOUSECURSOR 8
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  LLOWER,
  RLOWER,
  RAISE,
  NUMPAD,
  MOUSECURSOR,
  ADJUST,
};

/* Tap Dance */
enum {
  TD_SHIFTCAPS = 10,
  TD_LGUINMPD,
  TD_LGUIMSCS,
  X_TAP_DANCE
};



/* Tap Dance */

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_LLWR LLOWER
#define KC_RLWR RLOWER


#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DBUG DEBUG
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

#define KC_MCPW KC_POWER
#define KC_MCVU KC__VOLUP
#define KC_MCVD KC__VOLDOWN


//#define KC_ESCT MT(MOD_LCTL, KC_ESC) // tap Escape , Hold LCTL
#define KC_TBCT MT(MOD_LCTL, KC_TAB) // tap TAB , Hold LCTL

#define KC_BSAL MT(MOD_LALT, KC_BSPC) // tap BackSpace , Hold LALT
//#define KC_DLAL MT(MOD_LALT, KC_DEL) // tap Delete , Hold LALT
#define KC_BLRS MT(MOD_RSFT, KC_BSLS) // tap BackSlash , Hold RSFT


#define KC_CADL LCA(KC_DEL)
#define KC_STAB S(KC_TAB)


#define KC_SPLW LT(_LOWER,KC_SPC) // tap Space , Hold LowerLayer
#define KC_ENLW LT(_LOWER,KC_ENTER) // tap Enter , Hold LowerLayer
#define KC_ESRA LT(_RAISE,KC_ESC) // tap ESC , Hold RaiseLayer
#define KC_DLRA LT(_RAISE,KC_DEL) // tap Delete , Hold RaiseLayer

/* Tap Dance */
#define KC_SHCP TD(TD_SHIFTCAPS)
#define KC_LGNP TD(TD_LGUINMPD)
#define KC_LGMC TD(TD_LGUIMSCS)

#define KC_RTUB TD(TD_RTHUMB)
#define KC_LTUB TD(TD_LTHUMB)

#define KC_LLTB TD(TD_LLTHUMB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,MINS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,EQL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SHCP, Z  , X  , C  , V  , B  ,ESRA,     DLRA, N  , M  ,COMM,DOT ,SLSH,BLRS,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LTUB,LLWR,TBCT,         BSAL,RLWR,RTUB
  //                  `----+----+----'        `----+----+----'
  ),



  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,TILD,UNDS,PLUS,PIPE,LABK,               RABK,PGUP, UP ,PGDN,HOME,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,GRV ,MINS,EQL ,BSLS,LBRC,               RBRC,LEFT,DOWN,RGHT,END ,ENT ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         , RO ,JYEN,QUES,LPRN,LCBR,RASE,     RASE,RCBR,RPRN,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LLTB,    ,TAB ,         BSPC,    ,LGNP
  //                  `----+----+----'        `----+----+----'
  ),

  [_LLOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,F14 ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RLOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,F13 ,    ,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),



  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CADL, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----+              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,ENT ,
  //|----+----+----+----+----+----|----.    ,----|----+----+----+----+----+----|
         ,PLUS,MINS,EQL ,BSLS,QUOT,    ,         ,DQUO,SLSH,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LLTB,    ,    ,             ,    ,LGMC
  //                  `----+----+----'        `----+----+----'
  ),

  [_NUMPAD] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     NLCK,    ,    ,    ,    ,    ,                   , P7 , P8 , P9 ,PMNS,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HOME,PGUP, UP ,PGDN,LABK,               RABK, P4 , P5 , P6 ,PPLS,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,END ,LEFT,DOWN,RGHT,LPRN,               RPRN, P1 , P2 , P3 ,PAST,COLN,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,STAB,    ,      P0 ,EQL , P0 ,COMM,DOT ,PSLS,PENT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_MOUSECURSOR] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HOME,PGUP, UP ,PGDN,    ,               WH_D,BTN1,MS_U,BTN2,BTN3,ACL0,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,END ,LEFT,DOWN,RGHT,    ,               WH_L,MS_L,MS_D,MS_R,WH_R,ACL1,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,WH_U,LEFT,DOWN, UP ,RGHT,ACL2,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
),


  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     RST ,MUTE,VOLD,VOLU,    ,    ,                   ,    ,    ,    ,    ,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,               RTOG,RMOD,RHUI,RSAI,RVAI,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     MCPW,EJCT,MCVD,MCVU,    ,    ,                   ,DBUG,RHUD,RSAD,RVAD,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,    ,VOLD,VOLU,    ,    ,    ,         ,    ,    ,    ,    ,    ,BL_S,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};


/* TAP DANCE */
void shift_caps_down (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    register_code (KC_CAPS);
  } else {
    register_code (KC_RSFT);
  }
}

void shift_caps_up (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    unregister_code (KC_CAPS);
  } else {
    unregister_code (KC_RSFT);
  }
}

void dance_lgui_numpad_finished(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        register_code(KC_LGUI);
    }
}

void dance_lgui_numpad_reset(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        unregister_code(KC_LGUI);
    }
    else
    {
        uint8_t layer = biton32(layer_state);
        if (layer == _NUMPAD)
        {
            layer_off(_NUMPAD);
        } else {
            layer_on(_NUMPAD);
            layer_off(_MOUSECURSOR);
        }
    }
}


void dance_lgui_mousecursor_finished(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        register_code(KC_LGUI);
    }
}

void dance_lgui_mousecursor_reset(qk_tap_dance_state_t* state, void* user_data)
{
    if (state->count == 1)
    {
        unregister_code(KC_LGUI);
    }
    else
    {
        uint8_t layer = biton32(layer_state);
        if (layer == _MOUSECURSOR)
        {
            layer_off(_MOUSECURSOR);
        } else {
            layer_on(_MOUSECURSOR);
            layer_off(_NUMPAD);
        }
    }
}


qk_tap_dance_action_t tap_dance_actions[] = {


  // Tap once for Left Shift , trice for CAPS Lock
        [TD_SHIFTCAPS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, shift_caps_down, shift_caps_up),
  // tap once for LGUI , twice for move to NUMPAD layer
        [TD_LGUINMPD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lgui_numpad_finished, dance_lgui_numpad_reset),
  // tap once for LGUI , twice for move to MOUSECURSOR layer
        [TD_LGUIMSCS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lgui_mousecursor_finished, dance_lgui_mousecursor_reset),

        [TD_RTHUMB]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,rthumb_finished, rthumb_reset),
        [TD_LTHUMB]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,lthumb_finished, lthumb_reset),

        [TD_LLTHUMB]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL,llthumb_finished, llthumb_reset)
};


/* END TAP DANCE */


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool llower_pressed = false;
static uint16_t llower_pressed_time = 0;
static bool rlower_pressed = false;
static uint16_t rlower_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LLOWER:
      if (record->event.pressed) {
        llower_pressed = true;
        llower_pressed_time = record->event.time;

        layer_on(_LLOWER);
        layer_on(_LOWER);
        update_tri_layer(_LLOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LLOWER);
        layer_off(_LOWER);
        update_tri_layer(_LLOWER, _RAISE, _ADJUST);

        if (llower_pressed && (TIMER_DIFF_16(record->event.time, llower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
        }
        llower_pressed = false;
      }
      return false;
      break;
    case RLOWER:
      if (record->event.pressed) {
        rlower_pressed = true;
        rlower_pressed_time = record->event.time;

        layer_on(_RLOWER);
        layer_on(_LOWER);
        update_tri_layer(_RLOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RLOWER);
        layer_off(_LOWER);
        update_tri_layer(_RLOWER, _RAISE, _ADJUST);

        if (rlower_pressed && (TIMER_DIFF_16(record->event.time, rlower_pressed_time) < TAPPING_TERM)) {
          register_code(KC_ENTER);
          unregister_code(KC_ENTER);
        }
        rlower_pressed = false;
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    default:
      if (record->event.pressed) {
        // reset the flags
        llower_pressed = false;
        rlower_pressed = false;
      }
      break;
  }
  return true;
}