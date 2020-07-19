#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include "ui.hpp"

static void ui_draw_sidebar_background(UIState *s) {
  int sbr_x = !s->scene.uilayout_sidebarcollapsed ? 0 : -(sbr_w) + bdr_s * 2;
<<<<<<< HEAD

  nvgBeginPath(s->vg);
  nvgRect(s->vg, sbr_x, 0, sbr_w, vwp_h);
  nvgFillColor(s->vg, COLOR_BLACK_ALPHA(85));
  nvgFill(s->vg);
}

static void ui_draw_sidebar_settings_button(UIState *s) {
  bool settingsActive = s->active_app == cereal_UiLayoutState_App_settings;
=======
  ui_draw_rect(s->vg, sbr_x, 0, sbr_w, vwp_h, COLOR_BLACK_ALPHA(85));
}

static void ui_draw_sidebar_settings_button(UIState *s) {
  bool settingsActive = s->active_app == cereal::UiLayoutState::App::SETTINGS;
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  const int settings_btn_xr = !s->scene.uilayout_sidebarcollapsed ? settings_btn_x : -(sbr_w);

  ui_draw_image(s->vg, settings_btn_xr, settings_btn_y, settings_btn_w, settings_btn_h, s->img_button_settings, settingsActive ? 1.0f : 0.65f);
}

static void ui_draw_sidebar_home_button(UIState *s) {
<<<<<<< HEAD
  bool homeActive = s->active_app == cereal_UiLayoutState_App_home;
=======
  bool homeActive = s->active_app == cereal::UiLayoutState::App::HOME;
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  const int home_btn_xr = !s->scene.uilayout_sidebarcollapsed ? home_btn_x : -(sbr_w);

  ui_draw_image(s->vg, home_btn_xr, home_btn_y, home_btn_w, home_btn_h, s->img_button_home, homeActive ? 1.0f : 0.65f);
}

static void ui_draw_sidebar_network_strength(UIState *s) {
<<<<<<< HEAD
=======
  static std::map<cereal::ThermalData::NetworkStrength, int> network_strength_map = {
      {cereal::ThermalData::NetworkStrength::UNKNOWN, 1},
      {cereal::ThermalData::NetworkStrength::POOR, 2},
      {cereal::ThermalData::NetworkStrength::MODERATE, 3},
      {cereal::ThermalData::NetworkStrength::GOOD, 4},
      {cereal::ThermalData::NetworkStrength::GREAT, 5}};
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  const int network_img_h = 27;
  const int network_img_w = 176;
  const int network_img_x = !s->scene.uilayout_sidebarcollapsed ? 58 : -(sbr_w);
  const int network_img_y = 196;
<<<<<<< HEAD
  const int network_img = s->scene.networkType == cereal_ThermalData_NetworkType_none ?
                          s->img_network[0] : s->img_network[s->scene.networkStrength + 1];

  ui_draw_image(s->vg, network_img_x, network_img_y, network_img_w, network_img_h, network_img, 1.0f);
}
//thank you @eFini
static void ui_draw_sidebar_ip_addr(UIState *s) {
  const int network_ip_w = 176;
  const int network_ip_x = !s->scene.uilayout_sidebarcollapsed ? 54 : -(sbr_w);
  const int network_ip_y = 255;

  char network_ip_str[20];
  snprintf(network_ip_str, sizeof(network_ip_str), "%s", s->scene.ipAddr);
  nvgFillColor(s->vg, COLOR_WHITE);
  nvgFontSize(s->vg, 32);
  nvgFontFace(s->vg, "sans-regular");
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
  nvgTextBox(s->vg, network_ip_x, network_ip_y, network_ip_w, network_ip_str, NULL);
}

static void ui_draw_sidebar_battery_text(UIState *s) {
  const int battery_img_h = 36;
  const int battery_img_w = 76;
  const int battery_img_x = !s->scene.uilayout_sidebarcollapsed ? 150 : -(sbr_w);
  const int battery_img_y = 305;

  char battery_str[7];
  snprintf(battery_str, sizeof(battery_str), "%d%%%s", s->scene.batteryPercent, strcmp(s->scene.batteryStatus, "Charging") == 0 ? "+" : "-");
  nvgFillColor(s->vg, COLOR_WHITE);
  nvgFontSize(s->vg, 40);
  nvgFontFace(s->vg, "sans-regular");
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
  nvgTextBox(s->vg, battery_img_x, battery_img_y, battery_img_w, battery_str, NULL);
=======
  const int img_idx = s->scene.thermal.getNetworkType() == cereal::ThermalData::NetworkType::NONE ? 0 : network_strength_map[s->scene.thermal.getNetworkStrength()];
  ui_draw_image(s->vg, network_img_x, network_img_y, network_img_w, network_img_h, s->img_network[img_idx], 1.0f);
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
}

static void ui_draw_sidebar_battery_icon(UIState *s) {
  const int battery_img_h = 36;
  const int battery_img_w = 76;
  const int battery_img_x = !s->scene.uilayout_sidebarcollapsed ? 160 : -(sbr_w);
  const int battery_img_y = 255;

  int battery_img = s->scene.thermal.getBatteryStatus() == "Charging" ? s->img_battery_charging : s->img_battery;

  ui_draw_rect(s->vg, battery_img_x + 6, battery_img_y + 5,
               ((battery_img_w - 19) * (s->scene.thermal.getBatteryPercent() * 0.01)), battery_img_h - 11, COLOR_WHITE);

  ui_draw_image(s->vg, battery_img_x, battery_img_y, battery_img_w, battery_img_h, battery_img, 1.0f);
}

<<<<<<< HEAD


static void ui_draw_sidebar_network_type(UIState *s) {
  const int network_x = !s->scene.uilayout_sidebarcollapsed ? 50 : -(sbr_w);
  const int network_y = 300;
=======
static void ui_draw_sidebar_network_type(UIState *s) {
  static std::map<cereal::ThermalData::NetworkType, const char *> network_type_map = {
      {cereal::ThermalData::NetworkType::NONE, "--"},
      {cereal::ThermalData::NetworkType::WIFI, "WiFi"},
      {cereal::ThermalData::NetworkType::CELL2_G, "2G"},
      {cereal::ThermalData::NetworkType::CELL3_G, "3G"},
      {cereal::ThermalData::NetworkType::CELL4_G, "4G"},
      {cereal::ThermalData::NetworkType::CELL5_G, "5G"}};
  const int network_x = !s->scene.uilayout_sidebarcollapsed ? 50 : -(sbr_w);
  const int network_y = 273;
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  const int network_w = 100;
  const char *network_type = network_type_map[s->scene.thermal.getNetworkType()];
  nvgFillColor(s->vg, COLOR_WHITE);
  nvgFontSize(s->vg, 48);
  nvgFontFaceId(s->vg, s->font_sans_regular);
  nvgTextAlign(s->vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
  nvgTextBox(s->vg, network_x, network_y, network_w, network_type ? network_type : "--", NULL);
}

static void ui_draw_sidebar_metric(UIState *s, const char* label_str, const char* value_str, const int severity, const int y_offset, const char* message_str) {
  const int metric_x = !s->scene.uilayout_sidebarcollapsed ? 30 : -(sbr_w);
  const int metric_y = 338 + y_offset;
  const int metric_w = 240;
  const int metric_h = message_str ? strchr(message_str, '\n') ? 124 : 100 : 148;

  NVGcolor status_color;

  if (severity == 0) {
    status_color = COLOR_WHITE;
  } else if (severity == 1) {
    status_color = COLOR_YELLOW;
  } else if (severity > 1) {
    status_color = COLOR_RED;
  }

<<<<<<< HEAD
  nvgBeginPath(s->vg);
  nvgRoundedRect(s->vg, metric_x, metric_y, metric_w, metric_h, 20);
  nvgStrokeColor(s->vg, severity > 0 ? COLOR_WHITE : COLOR_WHITE_ALPHA(85));
  nvgStrokeWidth(s->vg, 2);
  nvgStroke(s->vg);
=======
  ui_draw_rect(s->vg, metric_x, metric_y, metric_w, metric_h,
               severity > 0 ? COLOR_WHITE : COLOR_WHITE_ALPHA(85), 20, 2);
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d

  nvgBeginPath(s->vg);
  nvgRoundedRectVarying(s->vg, metric_x + 6, metric_y + 6, 18, metric_h - 12, 25, 0, 0, 25);
  nvgFillColor(s->vg, status_color);
  nvgFill(s->vg);

  if (!message_str) {
    nvgFillColor(s->vg, COLOR_WHITE);
    nvgFontSize(s->vg, 78);
    nvgFontFaceId(s->vg, s->font_sans_bold);
    nvgTextAlign(s->vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
    nvgTextBox(s->vg, metric_x + 50, metric_y + 50, metric_w - 60, value_str, NULL);

    nvgFillColor(s->vg, COLOR_WHITE);
<<<<<<< HEAD
    nvgFontSize(s->vg, 46);
=======
    nvgFontSize(s->vg, 48);
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
    nvgFontFaceId(s->vg, s->font_sans_regular);
    nvgTextAlign(s->vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
    nvgTextBox(s->vg, metric_x + 50, metric_y + 50 + 66, metric_w - 60, label_str, NULL);
  } else {
    nvgFillColor(s->vg, COLOR_WHITE);
<<<<<<< HEAD
    nvgFontSize(s->vg, 46);
=======
    nvgFontSize(s->vg, 48);
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
    nvgFontFaceId(s->vg, s->font_sans_bold);
    nvgTextAlign(s->vg, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);
    nvgTextBox(s->vg, metric_x + 35, metric_y + (strchr(message_str, '\n') ? 40 : 50), metric_w - 50, message_str, NULL);
  }
}

static void ui_draw_sidebar_temp_metric(UIState *s) {
<<<<<<< HEAD
  int temp_severity;
=======
  static std::map<cereal::ThermalData::ThermalStatus, const int> temp_severity_map = {
      {cereal::ThermalData::ThermalStatus::GREEN, 0},
      {cereal::ThermalData::ThermalStatus::YELLOW, 1},
      {cereal::ThermalData::ThermalStatus::RED, 2},
      {cereal::ThermalData::ThermalStatus::DANGER, 3}};
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  char temp_label_str[32];
  char temp_value_str[32];
  char temp_value_unit[32];
  const int temp_y_offset = 0;
<<<<<<< HEAD

  if (s->scene.thermalStatus == cereal_ThermalData_ThermalStatus_green) {
    temp_severity = 0;
  } else if (s->scene.thermalStatus == cereal_ThermalData_ThermalStatus_yellow) {
    temp_severity = 1;
  } else if (s->scene.thermalStatus == cereal_ThermalData_ThermalStatus_red) {
    temp_severity = 2;
  } else if (s->scene.thermalStatus == cereal_ThermalData_ThermalStatus_danger) {
    temp_severity = 3;
  }

  snprintf(temp_value_str, sizeof(temp_value_str), "%d", s->scene.paTemp);
=======
  snprintf(temp_value_str, sizeof(temp_value_str), "%d", s->scene.thermal.getPa0());
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  snprintf(temp_value_unit, sizeof(temp_value_unit), "%s", "°C");
  snprintf(temp_label_str, sizeof(temp_label_str), "%s", "TEMP");
  strcat(temp_value_str, temp_value_unit);

<<<<<<< HEAD
  ui_draw_sidebar_metric(s, temp_label_str, temp_value_str, temp_severity, temp_y_offset, NULL);
}

static void ui_draw_sidebar_panda_metric(UIState *s) {
  int panda_severity;
=======
  ui_draw_sidebar_metric(s, temp_label_str, temp_value_str, temp_severity_map[s->scene.thermal.getThermalStatus()], temp_y_offset, NULL);
}

static void ui_draw_sidebar_panda_metric(UIState *s) {
  int panda_severity = 2;
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  char panda_message_str[32];
  const int panda_y_offset = 32 + 148;

  if (s->scene.hwType == cereal::HealthData::HwType::UNKNOWN) {
    panda_severity = 2;
<<<<<<< HEAD
    snprintf(panda_message_str, sizeof(panda_message_str), "%s", "PANDA\nN/A");
  } else if (s->scene.hwType == cereal_HealthData_HwType_whitePanda) {
    panda_severity = 0;
    snprintf(panda_message_str, sizeof(panda_message_str), "%s", "PANDA\nACTIVE");
  } else if (
      (s->scene.hwType == cereal_HealthData_HwType_greyPanda) ||
      (s->scene.hwType == cereal_HealthData_HwType_blackPanda) ||
      (s->scene.hwType == cereal_HealthData_HwType_uno)) {
      if (s->scene.satelliteCount == -1) {
        panda_severity = 0;
      } else {
        if (s->scene.satelliteCount < 6) {
          panda_severity = 1;
        } else if (s->scene.satelliteCount >= 6) {
          panda_severity = 0;
        }
      }
      snprintf(panda_message_str, sizeof(panda_message_str), "%s %d", "PANDA\nGPS:", s->scene.satelliteCount);
=======
    snprintf(panda_message_str, sizeof(panda_message_str), "%s", "NO\nVEHICLE");
  } else {
    if (s->started){
      if (s->scene.satelliteCount < 6) {
        panda_severity = 1;
        snprintf(panda_message_str, sizeof(panda_message_str), "%s", "VEHICLE\nNO GPS");
      } else if (s->scene.satelliteCount >= 6) {
        panda_severity = 0;
        snprintf(panda_message_str, sizeof(panda_message_str), "%s", "VEHICLE\nGOOD GPS");
      }
    } else {
      panda_severity = 0;
      snprintf(panda_message_str, sizeof(panda_message_str), "%s", "VEHICLE\nONLINE");
    }
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  }

  ui_draw_sidebar_metric(s, NULL, NULL, panda_severity, panda_y_offset, panda_message_str);
}

static void ui_draw_sidebar_connectivity(UIState *s) {
  if (s->scene.athenaStatus == NET_DISCONNECTED) {
<<<<<<< HEAD
    ui_draw_sidebar_metric(s, NULL, NULL, 1, 180+158, "ATHENA\nOFFLINE");
  } else if (s->scene.athenaStatus == NET_CONNECTED) {
    ui_draw_sidebar_metric(s, NULL, NULL, 0, 180+158, "ATHENA\nONLINE");
  } else {
    ui_draw_sidebar_metric(s, NULL, NULL, 2, 180+158, "ATHENA\nERROR");
=======
    ui_draw_sidebar_metric(s, NULL, NULL, 1, 180+158, "CONNECT\nOFFLINE");
  } else if (s->scene.athenaStatus == NET_CONNECTED) {
    ui_draw_sidebar_metric(s, NULL, NULL, 0, 180+158, "CONNECT\nONLINE");
  } else {
    ui_draw_sidebar_metric(s, NULL, NULL, 2, 180+158, "CONNECT\nERROR");
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  }
}

void ui_draw_sidebar(UIState *s) {
  ui_draw_sidebar_background(s);
<<<<<<< HEAD
  ui_draw_sidebar_settings_button(s);
  ui_draw_sidebar_home_button(s);
  ui_draw_sidebar_network_strength(s);
  ui_draw_sidebar_ip_addr(s);
  ui_draw_sidebar_battery_text(s);
=======
  if (s->scene.uilayout_sidebarcollapsed){
    return;
  }
  ui_draw_sidebar_settings_button(s);
  ui_draw_sidebar_home_button(s);
  ui_draw_sidebar_network_strength(s);
  ui_draw_sidebar_battery_icon(s);
>>>>>>> b205dd6954ad6d795fc04d66e0150675b4fae28d
  ui_draw_sidebar_network_type(s);
  ui_draw_sidebar_temp_metric(s);
  ui_draw_sidebar_panda_metric(s);
  ui_draw_sidebar_connectivity(s);
}
