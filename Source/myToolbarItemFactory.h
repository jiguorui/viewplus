/*
  ==============================================================================

    myToolbarItemFactory.h
    Created: 6 Mar 2014 4:20:55pm
    Author:  jiguo_000

  ==============================================================================
*/

#ifndef MYTOOLBARITEMFACTORY_H_INCLUDED
#define MYTOOLBARITEMFACTORY_H_INCLUDED

#if 0
    //==============================================================================
    class DemoToolbarItemFactory   : public ToolbarItemFactory
    {
    public:
        DemoToolbarItemFactory() {}

        //==============================================================================
        // Each type of item a toolbar can contain must be given a unique ID. These
        // are the ones we'll use in this demo.
        enum DemoToolbarItemIds
        {
            doc_new         = 1,
            doc_open        = 2,
            doc_save        = 3,
            doc_saveAs      = 4,
            edit_copy       = 5,
            edit_cut        = 6,
            edit_paste      = 7,
            juceLogoButton  = 8,
            customComboBox  = 9
        };

        void getAllToolbarItemIds (Array<int>& ids) override
        {
            // This returns the complete list of all item IDs that are allowed to
            // go in our toolbar. Any items you might want to add must be listed here. The
            // order in which they are listed will be used by the toolbar customisation panel.

            ids.add (doc_new);
            ids.add (doc_open);
            ids.add (doc_save);
            ids.add (doc_saveAs);
            ids.add (edit_copy);
            ids.add (edit_cut);
            ids.add (edit_paste);
            ids.add (juceLogoButton);
            ids.add (customComboBox);

            // If you're going to use separators, then they must also be added explicitly
            // to the list.
            ids.add (separatorBarId);
            ids.add (spacerId);
            ids.add (flexibleSpacerId);
        }

        void getDefaultItemSet (Array<int>& ids) override
        {
            // This returns an ordered list of the set of items that make up a
            // toolbar's default set. Not all items need to be on this list, and
            // items can appear multiple times (e.g. the separators used here).
            ids.add (doc_new);
            ids.add (doc_open);
            ids.add (doc_save);
            ids.add (doc_saveAs);
            ids.add (spacerId);
            ids.add (separatorBarId);
            ids.add (edit_copy);
            ids.add (edit_cut);
            ids.add (edit_paste);
            ids.add (separatorBarId);
            ids.add (flexibleSpacerId);
            ids.add (customComboBox);
            ids.add (flexibleSpacerId);
            ids.add (separatorBarId);
            ids.add (juceLogoButton);
        }

        ToolbarItemComponent* createItem (int itemId) override
        {
            switch (itemId)
            {
                case doc_new:           return createButtonFromZipFileSVG (itemId, "new", "document-new.svg");
                case doc_open:          return createButtonFromZipFileSVG (itemId, "open", "document-open.svg");
                case doc_save:          return createButtonFromZipFileSVG (itemId, "save", "document-save.svg");
                case doc_saveAs:        return createButtonFromZipFileSVG (itemId, "save as", "document-save-as.svg");
                case edit_copy:         return createButtonFromZipFileSVG (itemId, "copy", "edit-copy.svg");
                case edit_cut:          return createButtonFromZipFileSVG (itemId, "cut", "edit-cut.svg");
                case edit_paste:        return createButtonFromZipFileSVG (itemId, "paste", "edit-paste.svg");
                case juceLogoButton:    return new ToolbarButton (itemId, "juce!", Drawable::createFromImageData (BinaryData::juce_icon_png, BinaryData::juce_icon_pngSize), 0);
                case customComboBox:    return new CustomToolbarComboBox (itemId);
                default:                break;
            }

            return 0;
        }

    private:
        StringArray iconNames;
        OwnedArray<Drawable> iconsFromZipFile;

        // This is a little utility to create a button with one of the SVG images in
        // our embedded ZIP file "icons.zip"
        ToolbarButton* createButtonFromZipFileSVG (const int itemId, const String& text, const String& filename)
        {
            if (iconsFromZipFile.size() == 0)
            {
                // If we've not already done so, load all the images from the zip file..
                MemoryInputStream iconsFileStream (BinaryData::icons_zip, BinaryData::icons_zipSize, false);
                ZipFile icons (&iconsFileStream, false);

                for (int i = 0; i < icons.getNumEntries(); ++i)
                {
                    ScopedPointer<InputStream> svgFileStream (icons.createStreamForEntry (i));

                    if (svgFileStream != 0)
                    {
                        iconNames.add (icons.getEntry(i)->filename);
                        iconsFromZipFile.add (Drawable::createFromImageDataStream (*svgFileStream));
                    }
                }
            }

            Drawable* image = iconsFromZipFile [iconNames.indexOf (filename)]->createCopy();
            return new ToolbarButton (itemId, text, image, 0);
        }

        // Demonstrates how to put a custom component into a toolbar - this one contains
        // a ComboBox.
        class CustomToolbarComboBox : public ToolbarItemComponent
        {
        public:
            CustomToolbarComboBox (const int toolbarItemId)
                : ToolbarItemComponent (toolbarItemId, "Custom Toolbar Item", false),
                  comboBox ("demo toolbar combo box")
            {
                addAndMakeVisible (comboBox);

                for (int i = 1; i < 20; ++i)
                    comboBox.addItem ("Toolbar ComboBox item " + String (i), i);

                comboBox.setSelectedId (1);
                comboBox.setEditableText (true);
            }

            bool getToolbarItemSizes (int /*toolbarDepth*/, bool isVertical,
                                      int& preferredSize, int& minSize, int& maxSize) override
            {
                if (isVertical)
                    return false;

                preferredSize = 250;
                minSize = 80;
                maxSize = 300;
                return true;
            }

            void paintButtonArea (Graphics&, int, int, bool, bool) override
            {
            }

            void contentAreaChanged (const Rectangle<int>& newArea) override
            {
                comboBox.setSize (newArea.getWidth() - 2,
                                  jmin (newArea.getHeight() - 2, 22));

                comboBox.setCentrePosition (newArea.getCentreX(), newArea.getCentreY());
            }

        private:
            ComboBox comboBox;
        };
    };
#endif

#endif  // MYTOOLBARITEMFACTORY_H_INCLUDED
