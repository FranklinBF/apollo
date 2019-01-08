/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/transit/protocol/llc_auxiliaryfeedback_120.h"
#include "gtest/gtest.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace transit {

using ::apollo::drivers::canbus::Byte;

class llc_auxiliaryfeedback_120Test : public ::testing ::Test {
 public:
 protected:
  virtual void SetUp() {
    // setup parameters
  }
  Llcauxiliaryfeedback120 Llcauxiliary_feedback120_;
};

const std::uint8_t bytes = 0xFF;
std::int32_t length = 1;

TEST_F(llc_auxiliaryfeedback_120Test, inverter) {
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_inverter(&bytes, length), true);
}

TEST_F(llc_auxiliaryfeedback_120Test, ch) {
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch8(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch7(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch6(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch5(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch4(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch3(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch2(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_pdu_ch1(&bytes, length), false);
}

TEST_F(llc_auxiliaryfeedback_120Test, light_horn) {
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_hazardlights(&bytes, length),
            false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_ledgreenon(&bytes, length),
            false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_horn(&bytes, length), true);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_buzzeron(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_turnsignal(&bytes, length),
            false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_lowbeam(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_highbeam(&bytes, length), false);
  EXPECT_EQ(Llcauxiliary_feedback120_.llc_fbk_ledredon(&bytes, length), false);
  EXPECT_EQ(
      Llcauxiliary_feedback120_.llc_fbk_autonomybuttonpressed(&bytes, length),
      false);
}

}  // namespace transit
}  // namespace canbus
}  // namespace apollo
