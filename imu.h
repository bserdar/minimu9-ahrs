#pragma once

#include "vector.h"

class imu
{
public:
  virtual void read_raw()
  {
    read_mag_raw();
    read_acc_raw();
    read_gyro_raw();
  }

  virtual void read_acc_raw() = 0;
  virtual void read_mag_raw() = 0;
  virtual void read_gyro_raw() = 0;

  virtual float get_acc_scale() const = 0;
  virtual float get_gyro_scale() const = 0;

  int32_t mlo[3];
  int32_t mhi[3];
  int32_t alo[3];
  int32_t ahi[3];
  int32_t glo[3];
  int32_t ghi[3];

  // TODO: remove stuff below this point

  // Scaled readings
  virtual vector read_mag() = 0;  // In body coords, scaled to -1..1 range
  virtual vector read_acc() = 0;  // In body coords, with units = g
  virtual vector read_gyro() = 0; // In body coords, with units = rad/sec
  virtual vector read_mag_hi() {}
  virtual vector read_acc_hi() {}
  virtual vector read_gyro_hi() {}
  void read(){ read_mag(); read_acc(); read_gyro(); }

  virtual void measure_offsets() = 0;
  virtual void enable() = 0;
  virtual void load_calibration() = 0;

  vector gyro_offset_lo,gyro_offset_hi;
  int_vector mag_min, mag_max;
};
