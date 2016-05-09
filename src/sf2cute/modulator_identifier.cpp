/// @file
/// SoundFont 2 Key members of Modulator class implementation.
///
/// @author gocha <https://github.com/gocha>

#include <sf2cute/modulator_identifier.hpp>

#include <stdint.h>

namespace sf2cute {

/// Constructs a new SFModulatorIdentifier.
SFModulatorIdentifier::SFModulatorIdentifier() :
    source_op_(SFModulator(0)),
    destination_op_(SFGenerator(0)),
    amount_source_op_(SFModulator(0)) {
}

/// Constructs a new SFModulatorIdentifier using the specified controllers.
SFModulatorIdentifier::SFModulatorIdentifier(SFModulator source_op,
    SFGenerator destination_op,
    SFModulator amount_source_op) :
    source_op_(std::move(source_op)),
    destination_op_(std::move(destination_op)),
    amount_source_op_(std::move(amount_source_op)) {
}

/// Returns the source of data for the modulator.
SFModulator SFModulatorIdentifier::source_op() const noexcept {
  return source_op_;
}

/// Sets the source of data for the modulator.
void SFModulatorIdentifier::set_source_op(SFModulator source_op) {
  source_op_ = std::move(source_op);
}

/// Returns the destination of the modulator.
SFGenerator SFModulatorIdentifier::destination_op() const noexcept {
  return destination_op_;
}

/// Sets the destination of the modulator.
void SFModulatorIdentifier::set_destination_op(SFGenerator destination_op) {
  destination_op_ = std::move(destination_op);
}

/// Returns the modulation source to be applied to the modulation amount.
SFModulator SFModulatorIdentifier::amount_source_op() const noexcept {
  return amount_source_op_;
}

/// Sets the modulation source to be applied to the modulation amount.
void SFModulatorIdentifier::set_amount_source_op(SFModulator amount_source_op) {
  amount_source_op_ = std::move(amount_source_op);
}

} // namespace sf2cute
