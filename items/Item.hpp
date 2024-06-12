#pragma once

#include <string>
#include <utility>
#include <vector>
#ifdef INCLUDE_QT
#include <QDebug>
#endif

#include "enums.hpp"
#include "lce/blocks/mapcolors.hpp"
#include "types.hpp"


namespace lce::items {

    class Item {
        const std::string name;
        const std::string identifier;
        const uint16_t id{};
        const uint8_t dataTag{};
        const EntityEquipSlot armorType = EntityEquipSlot::NONE;
        const int8_t enchantability = 1;
        const ItemType type{};
        const bool damageable{};

    public:
        Item() = default;
        Item(const uint16_t id, const uint8_t dataTag, const ItemType type, std::string itemName,
             std::string identifier, const bool damageable, EntityEquipSlot const armorType,
             const int8_t enchantability)
            : id(id), dataTag(dataTag), type(type), name(std::move(itemName)), identifier(std::move(identifier)),
              damageable(damageable), armorType(armorType), enchantability(enchantability) {}

        Item(const uint16_t id, const uint8_t dataTag, const ItemType type, std::string itemName,
             std::string identifier, const bool damageable = false)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), damageable,
                   EntityEquipSlot::NONE, 1) {}
        Item(const uint16_t id, const uint8_t dataTag, const ItemType type, std::string itemName,
             std::string identifier, const bool damageable, const int8_t enchantability)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), damageable, EntityEquipSlot::NONE,
                   enchantability) {}
        Item(const uint16_t id, const uint8_t dataTag, const ItemType type, std::string itemName,
             std::string identifier, const int8_t enchantability)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), false, EntityEquipSlot::NONE,
                   enchantability) {}
        Item(const uint16_t id, const uint8_t dataTag, const ItemType type, std::string itemName,
             std::string identifier, const EntityEquipSlot armorType, const int8_t enchantability)
            : Item(id, dataTag, type, std::move(itemName), std::move(identifier), false, armorType, enchantability) {}
        Item(const uint16_t id, const uint8_t dataTag, std::string itemName, std::string identifier)
            : Item(id, dataTag, ItemType::ItemBlock, std::move(itemName), std::move(identifier), false,
                   EntityEquipSlot::NONE, 1) {}


        ND uint16_t getID() const { return id; }
        ND uint8_t getDataTag() const { return dataTag; }
        ND ItemType getItemType() const { return type; }
        ND std::string getName() const { return name; }
        ND std::string getIdentifier() const { return identifier; }
        ND bool isDamageable() const { return damageable; }
        ND EntityEquipSlot getArmorType() const { return armorType; }
        ND int8_t getCost() const { return enchantability; }

        friend std::ostream& operator<<(std::ostream& out, const Item& item) {
            out << item.getName();
            return out;
        }

#ifdef INCLUDE_QT
        friend QDebug operator<<(QDebug out, const Item& item) {
            out.nospace() << QString::fromStdString(item.getName());
            return out.nospace();
        }
#endif
    };

}
