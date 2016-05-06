/// @file
/// SoundFont 2 Preset class header.
///
/// @author gocha <https://github.com/gocha>

#ifndef SF2CUTE_PRESET_HPP_
#define SF2CUTE_PRESET_HPP_

#include <stdint.h>
#include <memory>
#include <utility>
#include <functional>
#include <string>
#include <vector>

namespace sf2cute {

class SFPresetZone;
class SoundFont;

/// The SFPreset class represents a preset.
///
/// @remarks This class represents the official sfPresetHeader type.
/// @see "7.2 The PHDR Sub-chunk".
/// In SoundFont Technical Specification 2.04.
class SFPreset {
  friend class SFPresetZone;
  friend class SoundFont;

public:
  /// The bank number for General MIDI drums.
  static constexpr uint16_t kPercussionBank = 128;

  /// Maximum length of preset name (excluding the terminator byte), in terms of bytes.
  static constexpr std::string::size_type kMaxNameLength = 20 - 1;

  /// Constructs a new empty preset.
  SFPreset();

  /// Constructs a new empty SFPreset using the specified name.
  /// @param name the name of the preset.
  explicit SFPreset(std::string name);

  /// Constructs a new SFPreset using the specified name and preset numbers.
  /// @param name the name of the preset.
  /// @param preset_number the preset number.
  /// @param bank the bank number.
  SFPreset(std::string name, uint16_t preset_number, uint16_t bank);

  /// Constructs a new SFPreset using the specified name, preset numbers and zones.
  /// @param name the name of the preset.
  /// @param preset_number the preset number.
  /// @param bank the bank number.
  /// @param zones a collection of preset zones to be assigned to the preset.
  SFPreset(std::string name,
      uint16_t preset_number,
      uint16_t bank,
      std::vector<SFPresetZone> zones);

  /// Constructs a new SFPreset using the specified name, preset numbers, zones and global zone.
  /// @param name the name of the preset.
  /// @param preset_number the preset number.
  /// @param bank the bank number.
  /// @param zones a collection of preset zones to be assigned to the preset.
  /// @param global_zone a global zone to be assigned to the preset.
  SFPreset(std::string name,
      uint16_t preset_number,
      uint16_t bank,
      std::vector<SFPresetZone> zones,
      SFPresetZone global_zone);

  /// Constructs a new copy of specified SFPreset.
  /// @param origin a SFPreset object.
  SFPreset(const SFPreset & origin);

  /// Copy-assigns a new value to the SFPreset, replacing its current contents.
  /// @param origin a SFPreset object.
  SFPreset & operator=(const SFPreset & origin);

  /// Acquires the contents of specified SFPreset.
  /// @param origin a SFPreset object.
  SFPreset(SFPreset && origin);

  /// Move-assigns a new value to the SFPreset, replacing its current contents.
  /// @param origin a SFPreset object.
  SFPreset & operator=(SFPreset && origin);

  /// Destructs the SFPreset.
  ~SFPreset() = default;

  /// Constructs a new SFPreset.
  /// @param args the arguments for the SFPreset constructor.
  /// @return the new SFPreset object.
  template<typename ... Args>
  static std::shared_ptr<SFPreset> New(Args && ... args) {
    return std::make_shared<SFPreset>(std::forward<Args>(args)...);
  }

  /// Returns the name of this preset.
  /// @return the name of this preset.
  const std::string & name() const;

  /// Sets the name of this preset.
  /// @param name the name of this preset.
  void set_name(std::string name);

  /// Returns the preset number.
  /// @return the preset number.
  uint16_t preset_number() const;

  /// Sets the preset number.
  /// @param preset_number the preset number.
  void set_preset_number(uint16_t preset_number);

  /// Returns the bank number.
  /// @return the bank number.
  uint16_t bank() const;

  /// Sets the bank number.
  /// @param bank the bank number.
  void set_bank(uint16_t bank);

  /// Returns the library.
  /// @return the library.
  /// @remarks The library field represents the unused dwLibrary field of sfPresetHeader type.
  uint32_t library() const;

  /// Sets the library.
  /// @param library the library.
  /// @remarks The library field represents the unused dwLibrary field of sfPresetHeader type.
  void set_library(uint32_t library);

  /// Returns the genre.
  /// @return the genre.
  /// @remarks The genre field represents the unused dwGenre field of sfPresetHeader type.
  uint32_t genre() const;

  /// Sets the genre.
  /// @param genre the genre.
  /// @remarks The genre field represents the unused dwGenre field of sfPresetHeader type.
  void set_genre(uint32_t genre);

  /// Returns the morphology.
  /// @return the morphology.
  /// @remarks The morphology field represents the unused dwMorphology field of sfPresetHeader type.
  uint32_t morphology() const;

  /// Sets the morphology.
  /// @param morphology the morphology.
  /// @remarks The morphology field represents the unused dwMorphology field of sfPresetHeader type.
  void set_morphology(uint32_t morphology);

  /// Returns the list of preset zones.
  /// @return the list of preset zones assigned to the preset.
  const std::vector<std::unique_ptr<SFPresetZone>> & zones() const;

  /// Adds a preset zone to the preset.
  /// @param zone a preset zone to be assigned to the preset.
  void AddZone(SFPresetZone zone);

  /// Removes a preset zone from the preset.
  /// @param position the preset zone to remove.
  void RemoveZone(
      std::vector<std::unique_ptr<SFPresetZone>>::const_iterator position);

  /// Removes preset zones from the preset.
  /// @param first the first preset zone to remove.
  /// @param last the last preset zone to remove.
  void RemoveZone(
      std::vector<std::unique_ptr<SFPresetZone>>::const_iterator first,
      std::vector<std::unique_ptr<SFPresetZone>>::const_iterator last);

  /// Removes preset zones from the preset.
  /// @param predicate unary predicate which returns true if the preset zone should be removed.
  void RemoveZoneIf(
      std::function<bool(const std::unique_ptr<SFPresetZone> &)> predicate);

  /// Removes all of the preset zones.
  void ClearZones();

  /// Returns true if the preset has a global zone.
  /// @return true if the preset has a global zone.
  bool has_global_zone() const;

  /// Returns the global zone.
  /// @return the global zone.
  SFPresetZone & global_zone() const;

  /// Sets the global zone.
  /// @param global_zone the global zone.
  void set_global_zone(SFPresetZone global_zone);

  /// Resets the global zone.
  void reset_global_zone();

  /// Returns true if the preset has a parent file.
  /// @return true if the preset has a parent file.
  bool has_parent_file() const;

  /// Returns the parent file.
  /// @return the parent file.
  SoundFont & parent_file() const;

private:
  /// Sets the parent file.
  /// @param parent_file the parent file.
  void set_parent_file(SoundFont & parent_file);

  /// Resets the parent file.
  void reset_parent_file();

  /// Sets backward references of every childlen elements.
  void SetBackwardReferences();

  /// The name of preset.
  std::string name_;

  /// The preset number.
  uint16_t preset_number_;

  /// The bank number.
  uint16_t bank_;

  /// The library.
  uint32_t library_;

  /// The genre.
  uint32_t genre_;

  /// The morphology.
  uint32_t morphology_;

  /// The list of preset zones.
  std::vector<std::unique_ptr<SFPresetZone>> zones_;

  /// The global zone.
  std::unique_ptr<SFPresetZone> global_zone_;

  /// The parent file.
  SoundFont * parent_file_;
};

} // namespace sf2cute

#endif // SF2CUTE_PRESET_HPP_
