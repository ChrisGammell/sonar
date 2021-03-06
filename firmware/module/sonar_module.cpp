#include "sonar_module.h"

namespace fk {

void TakeSonarReadings::task() {
    auto DistanceFromWaterBedInMeters = 1.0f;
    auto value = analogRead(A1);
    auto voltage = value * (3.3f / 1024.0f);
    auto distance = voltage * (1000.0f / 3.2f);
    auto depth = DistanceFromWaterBedInMeters - (distance / 100.0);

    auto i = 0;
    services().readings->done(i++, (float)value);
    services().readings->done(i++, distance);
    services().readings->done(i++, depth);
    services().readings->done(i++, DistanceFromWaterBedInMeters);

    transit<ModuleIdle>();
}

SonarModule::SonarModule(ModuleInfo &info)
    : Module(moduleBus, info) {
}

}
