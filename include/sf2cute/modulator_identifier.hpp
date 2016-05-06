/// @file
/// SoundFont 2 Key members of Modulator class header.
///
/// @author gocha <https://github.com/gocha>

#ifndef SF2CUTE_MODULATOR_IDENTIFIER_HPP_
#define SF2CUTE_MODULATOR_IDENTIFIER_HPP_

#include "types.hpp"
#include "modulator.hpp"

namespace sf2cute {

/// The SFModulatorIdentifier class represents the unique key of a modulator.
///
/// @remarks This class represents a part of the sfModList/sfInstModList type.
/// @see "7.4 The PMOD Sub-chunk". In SoundFont Technical Specification 2.04.
/// @see "7.8 The IMOD Sub-chunk". In SoundFont Technical Specification 2.04.
class SFModulatorIdentifier {
public:
  /// Constructs a new SFModulatorIdentifier.
  SFModulatorIdentifier();

  /// Constructs a new SFModulatorIdentifier using the specified controllers.
  /// @param source_op the source of data for the modulator.
  /// @param destination_op the destination of the modulator.
  /// @param amount_source_op the modulation source to be applied to the modulation amount.
  SFModulatorIdentifier(SFModulator source_op,
      SFGenerator destination_op,
      SFModulator amount_source_op);

  /// Constructs a new copy of specified SFModulatorIdentifier.
  /// @param origin a SFModulatorIdentifier object.
  SFModulatorIdentifier(const SFModulatorIdentifier & origin) = default;

  /// Copy-assigns a new value to the SFModulatorIdentifier, replacing its current contents.
  /// @param origin a SFModulatorIdentifier object.
  SFModulatorIdentifier & operator=(const SFModulatorIdentifier & origin) = default;

  /// Acquires the contents of specified SFModulatorIdentifier.
  /// @param origin a SFModulatorIdentifier object.
  SFModulatorIdentifier(SFModulatorIdentifier && origin) = default;

  /// Move-assigns a new value to the SFModulatorIdentifier, replacing its current contents.
  /// @param origin a SFModulatorIdentifier object.
  SFModulatorIdentifier & operator=(SFModulatorIdentifier && origin) = default;

  /// Destructs the SFModulatorIdentifier.
  ~SFModulatorIdentifier() = default;

  /// Returns the source of data for the modulator.
  /// @return the source of data for the modulator.
  SFModulator source_op() const;

  /// Sets the source of data for the modulator.
  /// @param source_op the source of data for the modulator.
  void set_source_op(SFModulator source_op);

  /// Returns the destination of the modulator.
  /// @return the destination of the modulator.
  SFGenerator destination_op() const;

  /// Sets the destination of the modulator.
  /// @param destination_op the destination of the modulator.
  void set_destination_op(SFGenerator destination_op);

  /// Returns the modulation source to be applied to the modulation amount.
  /// @return the modulation source to be applied to the modulation amount.
  SFModulator amount_source_op() const;

  /// Sets the modulation source to be applied to the modulation amount.
  /// @param amount_source_op the modulation source to be applied to the modulation amount.
  void set_amount_source_op(SFModulator amount_source_op);

  /// Indicates a SFModulatorIdentifier object is "equal to" the other one.
  /// @param x the first object to be compared.
  /// @param y the second object to be compared.
  /// @return true if a SFModulatorIdentifier object is "equal to" the other one.
  friend inline bool operator==(
      const SFModulatorIdentifier & x,
      const SFModulatorIdentifier & y) {
    return std::tie(x.source_op_, x.destination_op_, x.amount_source_op_) ==
      std::tie(y.source_op_, y.destination_op_, y.amount_source_op_);
  }

  /// Indicates a SFModulatorIdentifier object is "not equal to" the other one.
  /// @param x the first object to be compared.
  /// @param y the second object to be compared.
  /// @return true if a SFModulatorIdentifier object is "not equal to" the other one.
  friend inline bool operator!=(
      const SFModulatorIdentifier & x,
      const SFModulatorIdentifier & y) {
    return std::tie(x.source_op_, x.destination_op_, x.amount_source_op_) !=
      std::tie(y.source_op_, y.destination_op_, y.amount_source_op_);
  }

  /// Indicates a SFModulatorIdentifier object is "less than" the other one.
  /// @param x the first object to be compared.
  /// @param y the second object to be compared.
  /// @return true if a SFModulatorIdentifier object is "less than" the other one.
  friend inline bool operator<(
      const SFModulatorIdentifier & x,
      const SFModulatorIdentifier & y) {
    return std::tie(x.source_op_, x.destination_op_, x.amount_source_op_) <
      std::tie(y.source_op_, y.destination_op_, y.amount_source_op_);
  }

  /// Indicates a SFModulatorIdentifier object is "less than or equal to" the other one.
  /// @param x the first object to be compared.
  /// @param y the second object to be compared.
  /// @return true if a SFModulatorIdentifier object is "less than or equal to" the other one.
  friend inline bool operator<=(
      const SFModulatorIdentifier & x,
      const SFModulatorIdentifier & y) {
    return std::tie(x.source_op_, x.destination_op_, x.amount_source_op_) <=
      std::tie(y.source_op_, y.destination_op_, y.amount_source_op_);
  }

  /// Indicates a SFModulatorIdentifier object is "greater than" the other one.
  /// @param x the first object to be compared.
  /// @param y the second object to be compared.
  /// @return true if a SFModulatorIdentifier object is "greater than" the other one.
  friend inline bool operator>(
      const SFModulatorIdentifier & x,
      const SFModulatorIdentifier & y) {
    return std::tie(x.source_op_, x.destination_op_, x.amount_source_op_) >
      std::tie(y.source_op_, y.destination_op_, y.amount_source_op_);
  }

  /// Indicates a SFModulatorIdentifier object is "greater than or equal to" the other one.
  /// @param x the first object to be compared.
  /// @param y the second object to be compared.
  /// @return true if a SFModulatorIdentifier object is "greater than or equal to" the other one.
  friend inline bool operator>=(
      const SFModulatorIdentifier & x,
      const SFModulatorIdentifier & y) {
    return std::tie(x.source_op_, x.destination_op_, x.amount_source_op_) >=
      std::tie(y.source_op_, y.destination_op_, y.amount_source_op_);
  }

private:
  /// The source of data for the modulator.
  SFModulator source_op_;

  /// The destination of the modulator.
  SFGenerator destination_op_;

  /// The modulation source to be applied to the modulation amount.
  SFModulator amount_source_op_;
};

} // namespace sf2cute

#endif // SF2CUTE_MODULATOR_IDENTIFIER_HPP_
