#include <i2cdevice.h>

I2CDevice::I2CDevice(uint8_t addr, const char *bus) {
    _fd = open(bus, O_RDWR);
    ioctl(_fd, I2C_SLAVE, addr);
    // TODO: error checking
}

I2CDevice::~I2CDevice() {
    close(_fd);
}

ssize_t I2CDevice::write(const uint8_t *buf, size_t count) {
    return ::write(_fd, buf, count);
}

ssize_t I2CDevice::read(uint8_t *buf, size_t count) {
    return ::read(_fd, &buf, count);
}
