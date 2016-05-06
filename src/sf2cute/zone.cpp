/// @file
/// SoundFont 2 Zone class implemantation.
///
/// @author gocha <https://github.com/gocha>

#include <sf2cute/zone.hpp>

#include <algorithm>
#include <vector>

#include <sf2cute/generator_item.hpp>
#include <sf2cute/modulator_item.hpp>

namespace sf2cute {

/// Constructs a new empty SFZone.
SFZone::SFZone() {
}

/// Constructs a empty SFZone using the specified generators and modulators.
SFZone::SFZone(
    std::vector<SFGeneratorItem> generators,
    std::vector<SFModulatorItem> modulators) {
  // Set generators.
  generators_.reserve(generators.size());
  for (auto && generator : generators) {
    SetGenerator(std::move(generator));
  }

  // Set modulators.
  modulators_.reserve(modulators.size());
  for (auto && modulator : modulators) {
    SetModulator(std::move(modulator));
  }
}

/// Constructs a new copy of specified SFZone.
SFZone::SFZone(const SFZone & origin) {
  // Copy generators.
  generators_.reserve(origin.generators().size());
  for (const auto & generator : origin.generators()) {
    generators_.push_back(std::make_unique<SFGeneratorItem>(*generator));
  }

  // Copy modulators.
  modulators_.reserve(origin.modulators().size());
  for (const auto & modulator : origin.modulators()) {
    modulators_.push_back(std::make_unique<SFModulatorItem>(*modulator));
  }
}

/// Copy-assigns a new value to the SFZone, replacing its current contents.
SFZone & SFZone::operator=(const SFZone & origin) {
  // Copy generators.
  generators_.clear();
  generators_.reserve(origin.generators().size());
  for (const auto & generator : origin.generators()) {
    generators_.push_back(std::make_unique<SFGeneratorItem>(*generator));
  }

  // Copy modulators.
  modulators_.clear();
  modulators_.reserve(origin.modulators().size());
  for (const auto & modulator : origin.modulators()) {
    modulators_.push_back(std::make_unique<SFModulatorItem>(*modulator));
  }

  return *this;
}

/// Returns the list of generators.
const std::vector<std::unique_ptr<SFGeneratorItem>> & SFZone::generators() const {
  return generators_;
}

/// Sets a generator to the zone.
void SFZone::SetGenerator(SFGeneratorItem generator) {
  // Find the generator.
  const auto it = FindGenerator(generator.op());
  if (it == generators_.end()) {
    generators_.push_back(std::make_unique<SFGeneratorItem>(std::move(generator)));
  }
  else {
    const std::unique_ptr<SFGeneratorItem> & old_generator = *it;
    *old_generator = std::move(generator);
  }
}

/// Finds the generator which is the specified type.
const std::vector<std::unique_ptr<SFGeneratorItem>>::const_iterator
    SFZone::FindGenerator(SFGenerator op) const {
  return std::find_if(generators_.begin(), generators_.end(),
    [&op](const std::unique_ptr<SFGeneratorItem> & generator) {
      return generator->op() == op;
    });
}

/// Removes all of the generators.
void SFZone::ClearGenerators() {
  generators_.clear();
}

/// Returns the list of modulators.
const std::vector<std::unique_ptr<SFModulatorItem>> & SFZone::modulators() const {
  return modulators_;
}

/// Sets a modulator to the zone.
void SFZone::SetModulator(SFModulatorItem modulator) {
  // Find the modulator.
  const auto it = FindModulator(modulator.identifier());
  if (it == modulators_.end()) {
    modulators_.push_back(std::make_unique<SFModulatorItem>(std::move(modulator)));
  }
  else {
    const std::unique_ptr<SFModulatorItem> & old_modulator = *it;
    *old_modulator = std::move(modulator);
  }
}

/// Finds the modulator which is the specified type.
const std::vector<std::unique_ptr<SFModulatorItem>>::const_iterator
  SFZone::FindModulator(SFModulatorIdentifier identifier) const {
  return std::find_if(modulators_.begin(), modulators_.end(),
    [&identifier](const std::unique_ptr<SFModulatorItem> & modulator) {
      return modulator->identifier() == identifier;
    });
}

/// Removes all of the modulators.
void SFZone::ClearModulators() {
  modulators_.clear();
}

} // namespace sf2cute
