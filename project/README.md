# Powder Coating Management
#### Video Demo:  <https://youtu.be/-NXr84BIBAU>
#### Description:

The Powder Coating Management is a C# console application where you can add raw materials, create formulas, consult the data, and keep track of the information for each item. I currently work with powder coating development, and this app eliminates the need for storing paper, saving space, and helps to have more control over the formulas.

The app was built using object-oriented programming methods. Let me explain some of the main parts:

Program Class - This class prints the welcome message and uses methods to set the culture and initialize stock.

Product Class - This is the base class for both raw materials and formulas. It contains an ID, a name, and a price per kg. The class is abstract, so it can't be instantiated, and each field is encapsulated with properties.

RawMaterial Class - This class inherits from Product and contains the constructors and additional fields such as brandName, rawMaterialType, and a method called ConvertStringToSave.

RawMaterialType Enum - An enum that contains the types of different raw materials.

ISavable Interface - An interface containing the ConvertStringToSave method, which is used when saving the information to a txt file.

FormulaItem Class - This class takes a raw material and an amount, and it is created solely to build a formula.

Formula Class - This class contains the FormulaItem list, the constructors, date, the ConvertStringToSave method, and a method that calculates the price of the formula using the raw material price and the amount of each FormulaItem.

FormulaRepository and RawMaterialRepository Class - These classes contain the path and file name that will be used to store the data. They have methods like CheckForExistingFiles, which creates the file if it doesn't exist, and LoadDataFromFile, which loads the txt file information and instantiates the items to be loaded into the storage list in the Utilities class. These classes are also responsible for saving the data into the file using the SaveToFile method.

Utilities Class - This helper class includes the storage lists and the majority of methods used in the entire application. It has methods like ShowMenu and CreateFormula, which create formulas by selecting a raw material, specifying the amount, and prompting for the date. It also ensures the total amount is 1kg. The AddNewRawMaterial method creates a new raw material and adds it to the storage. Other methods include GenerateId, which automatically generates IDs based on the type of raw material or formula; IdExists, which ensures the ID being created is not already in use; SaveAllData, which saves the storage lists into a file by calling various methods; ShowFormulas, which generates a table to display the formulas; ShowFormulasMoreInfo, which shows all the information of a formula based on its ID; and EditRawMaterials, which allows editing the price, name, and manufacturer of the raw material. Raw materials cannot be deleted as it would create problems in formulas that use them. However, formulas can be deleted and edited. When changing the price of a raw material, the formula price will be updated when saving all the files in the main menu.