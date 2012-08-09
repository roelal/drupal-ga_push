(function ($) {
  ga_push_browser = Drupal.settings.ga_push_browser;

  $.each(ga_push_browser, function(index, value) {
    $(value['selector']).bind(value['bind'], function() {
      if (typeof(_gaq) == 'object') {
        _gaq.push(['_trackEvent', value['push'][0], value['push'][1], value['push'][2] , value['push'][3]]);
      }
    });
  });
})(jQuery);
